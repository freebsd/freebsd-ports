/*
 * unmakeself - extracts Makeself archives
 *
 * Copyright (C) 2005 Jean-Yves Lefort
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of Jean-Yves Lefort nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <getopt.h>
#include <archive.h>

static char *self = NULL;				/* program name */
static int extract_flags = ARCHIVE_EXTRACT_TIME;	/* bsdtar default */

static void
unmakeself_print_help (void)
{
  printf("Synopsis:\n");
  printf("  %s [OPTIONS] FILE\n", self);
  printf("\n");
  printf("Options:\n");
  printf("  -?, --help                  Show this help\n");
  printf("  -v, --version               Show version information\n");
  printf("  -k, --keep-old-files        Do not overwrite existing files\n");
  printf("  -m, --modification-time     Do not extract modification time\n");
  printf("  -o, --no-same-owner         Do not extract ownership\n");
  printf("  -p, --preserve-permissions  Preserve file permissions\n");
  printf("  -U, --unlink-first          Unlink files before creating them\n");
  printf("      --print-offset          Only print the offset, do not extract\n");
}

static void
unmakeself_print_version (void)
{
  printf("unmakeself version 1.0\n");
  printf("Copyright (C) 2005 Jean-Yves Lefort\n");
}

static void
unmakeself_extract (const char *filename, int print_offset)
{
  int fd;
  char buf[4096];
  int pos = 0;
  int last_newline = -1;
  int offset = -1;
  int done = 0;
  ssize_t len;

  fd = open(filename, O_RDONLY);
  if (fd < 0)
    {
      fprintf(stderr, "%s: unable to open %s: %s\n", self, filename, strerror(errno));
      exit(1);
    }

  /*
   * We find the start offset of the archive inside the shell script
   * by locating the first non-printable character following a
   * newline. The archive starts immediately after that newline.
   */
  while (! done && (len = read(fd, buf, sizeof(buf))) > 0)
    {
      int i;

      for (i = 0; i < len; i++, pos++)
	if (buf[i] == '\n')
	  last_newline = pos;
	else if (buf[i] != '\t' && (buf[i] < 32 || buf[i] > 126))
	  {
	    if (last_newline != -1)
	      offset = last_newline + 1;
	    
	    done = 1;
	    break;
	  }
    }

  if (offset != -1)		/* offset found */
    {
      if (print_offset)		/* only print the offset */
	printf("%i\n", offset);
      else			/* extract using libarchive */
	{
	  struct archive *archive;
	  struct archive_entry *entry;
	  int status;

	  if (lseek(fd, offset, SEEK_SET) < 0)
	    {
	      fprintf(stderr, "%s: unable to seek into %s: %s\n", self, filename, strerror(errno));
	      exit(1);
	    }
      
	  archive = archive_read_new();

	  if (archive_read_support_compression_all(archive) != ARCHIVE_OK)
	    fprintf(stderr, "%s: warning: unable to support all compression formats: %s\n", self, archive_error_string(archive));
	  if (archive_read_support_format_all(archive) != ARCHIVE_OK)
	    fprintf(stderr, "%s: warning: unable to support all archive formats: %s\n", self, archive_error_string(archive));

	  /* same block size as DEFAULT_BYTES_PER_BLOCK in bsdtar.h */
	  if (archive_read_open_fd(archive, fd, 20 * 512) != ARCHIVE_OK)
	    {
	      fprintf(stderr, "%s: unable to open %s with libarchive: %s\n", self, filename, archive_error_string(archive));
	      exit(1);
	    }
      
	  while ((status = archive_read_next_header(archive, &entry)) == ARCHIVE_OK)
	    if (archive_read_extract(archive, entry, extract_flags) != ARCHIVE_OK)
	      {
		fprintf(stderr, "%s: unable to extract %s: %s\n", self, filename, archive_error_string(archive));
		exit(1);
	      }

	  if (status != ARCHIVE_EOF)
	    {
	      fprintf(stderr, "%s: unable to read next header of %s: %s\n", self, filename, archive_error_string(archive));
	      exit(1);
	    }
      
	  if (archive_read_close(archive) != ARCHIVE_OK)
	    {
	      fprintf(stderr, "%s: unable to close %s with libarchive: %s\n", self, filename, archive_error_string(archive));
	      exit(1);
	    }
      
	  archive_read_finish(archive);
	}
    }
  else
    {
      if (len >= 0)		/* EOF, or couldn't find start offset */
	{
	  fprintf(stderr, "%s: %s is not a valid Makeself archive\n", self, filename);
	  exit(1);
	}
      else			/* read error */
	{
	  fprintf(stderr, "%s: unable to read %s: %s\n", self, filename, strerror(errno));
	  exit(1);
	}
    }

  if (close(fd) < 0)
    {
      fprintf(stderr, "%s: unable to close %s: %s\n", self, filename, strerror(errno));
      exit(1);
    }
}

int
main (int argc, char **argv)
{
  int print_offset = 0;
  const struct option options[] = {
    { "help",			no_argument,	NULL, 		'?'	},
    { "version",		no_argument,	NULL, 		'v'	},
    { "keep-old-files",		no_argument,	NULL, 		'k'	},
    { "modification-time",	no_argument,	NULL, 		'm'	},
    { "no-same-owner",		no_argument,	NULL, 		'o'	},
    { "preserve-permissions",	no_argument,	NULL, 		'p'	},
    { "unlink",			no_argument,	NULL, 		'U'	},
    { "unlink-first",		no_argument,	NULL, 		'U'	},
    { "print-offset",		no_argument,	&print_offset,	1	},
    { NULL,			0,		NULL,		0	}
  };
  int c;

  self = argc > 0 ? strdup(argv[0]) : "unmakeself";
  setlocale(LC_ALL, "");

  if (geteuid() == 0)		/* bsdtar does this */
    extract_flags |= ARCHIVE_EXTRACT_OWNER;

  while ((c = getopt_long(argc, argv, "?vkmpUx", options, NULL)) != -1)
    switch (c)
      {
      case '?':
	unmakeself_print_help();
	exit(0);
	break;

      case 'v':
	unmakeself_print_version();
	exit(0);
	break;

      case 'k':			/* GNU tar, bsdtar */
	extract_flags |= ARCHIVE_EXTRACT_NO_OVERWRITE;
	break;

      case 'm':			/* SUSv2, bsdtar */
	extract_flags &= ~ARCHIVE_EXTRACT_TIME;
	break;

      case 'o':			/* bsdtar */
	extract_flags &= ~ARCHIVE_EXTRACT_OWNER;
	break;

      case 'p':			/* GNU tar, star, bsdtar */
	extract_flags |= ARCHIVE_EXTRACT_PERM;
	extract_flags |= ARCHIVE_EXTRACT_ACL;
	extract_flags |= ARCHIVE_EXTRACT_FFLAGS;
	break;

      case 'U':			/* GNU tar, bsdtar */
	extract_flags |= ARCHIVE_EXTRACT_UNLINK;
	break;

      case 0:
	break;

      default:
	abort();
      }

  argc -= optind;
  argv += optind;

  if (argc != 1)
    {
      fprintf(stderr, "%s: a file to extract must be specified\n", self);
      exit(1);
    }

  unmakeself_extract(argv[0], print_offset);

  /* on some systems, the return value of main() is ignored */
  exit(0);

  return 0;
}
