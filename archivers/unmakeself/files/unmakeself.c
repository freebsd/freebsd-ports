/*
 * unmakeself - extracts Makeself archives
 *
 * Copyright (C) 2005, 2006 Jean-Yves Lefort
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
#include "config.h"

#define N_ELEMENTS(arr)		(sizeof(arr) / sizeof((arr)[0]))

static char *self;					/* program name */
static char *filename;
static struct archive *archive;
static int extract_flags = ARCHIVE_EXTRACT_TIME;	/* bsdtar default */

#ifndef HAS_MEMMEM
/* taken from lib/libc/string/memmem.c */
static void *
memmem(l, l_len, s, s_len)
	const void *l; size_t l_len;
	const void *s; size_t s_len;
{
	register char *cur, *last;
	const char *cl = (const char *)l;
	const char *cs = (const char *)s;

	/* we need something to compare */
	if (l_len == 0 || s_len == 0)
		return NULL;

	/* "s" must be smaller or equal to "l" */
	if (l_len < s_len)
		return NULL;

	/* special case where s_len == 1 */
	if (s_len == 1)
		return memchr(l, (int)*cs, l_len);

	/* the last position where its possible to find "s" in "l" */
	last = (char *)cl + l_len - s_len;

	for (cur = (char *)cl; cur <= last; cur++)
		if (cur[0] == cs[0] && memcmp(cur, cs, s_len) == 0)
			return cur;

	return NULL;
}
#endif /* HAS_MEMMEM */

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
  printf("unmakeself version 1.1\n");
  printf("Copyright (C) 2005, 2006 Jean-Yves Lefort\n");
}

static void
unmakeself_error (const char *func, const char *error)
{
  if (func)
    fprintf(stderr, "%s %s: %s() error: %s\n", self, filename, func, error);
  else
    fprintf(stderr, "%s %s: error: %s\n", self, filename, error);
  exit(1);
}

static void
unmakeself_handle_libc_result (int result, const char *func)
{
  if (result < 0)
    unmakeself_error(func, strerror(errno));
}

static void
unmakeself_handle_libarchive_result_full (int ok, const char *func)
{
  if (! ok)
    unmakeself_error(func, archive_error_string(archive));
}

static void
unmakeself_handle_libarchive_result (int result, const char *func)
{
  unmakeself_handle_libarchive_result_full(result == ARCHIVE_OK, func);
}

static ssize_t
unmakeself_read (int fd, void *buf, size_t nbytes)
{
  ssize_t result;

  result = read(fd, buf, nbytes);
  unmakeself_handle_libc_result(result, "read");

  return result;
}

static off_t
unmakeself_lseek (int fd, off_t offset, int whence)
{
  off_t result;

  result = lseek(fd, offset, whence);
  unmakeself_handle_libc_result(result, "lseek");

  return result;
}

static off_t
unmakeself_get_offset (int fd)
{
  static const char *magic_numbers[] = {
    "\n\037\213",		/* newline + gzip */
    "\nBZh"			/* newline + bzip2 */
  };
  char buf[4096];
  ssize_t len;
  off_t pos = 0;
  off_t last_newline = -1;
  int i;

  /*
   * First try to find a gzip or bzip2 magic number following a newline.
   */

  while ((len = unmakeself_read(fd, buf, sizeof(buf))) > 0)
    {
      for (i = 0; i < N_ELEMENTS(magic_numbers); i++)
	{
	  char *start;

	  start = memmem(buf, len, magic_numbers[i], strlen(magic_numbers[i]));
	  if (start)
	    return pos + (start - buf) + 1;
	}
      pos += len;
    }

  /*
   * Then fallback to locating the first non-printable character
   * following a newline. The archive should start immediately after
   * that newline.
   */

  unmakeself_lseek(fd, 0, SEEK_SET);
  pos = 0;

  while ((len = unmakeself_read(fd, buf, sizeof(buf))) > 0)
    for (i = 0; i < len; i++, pos++)
      if (buf[i] == '\n')
	last_newline = pos;
      else if (buf[i] != '\t' && (buf[i] < 32 || buf[i] > 126))
	{
	  if (last_newline != -1)
	    return last_newline + 1;
	}

  return -1;			/* not found */
}

static void
unmakeself_extract (int print_offset)
{
  int fd;
  off_t offset;

  fd = open(filename, O_RDONLY);
  unmakeself_handle_libc_result(fd, "open");

  offset = unmakeself_get_offset(fd);
  if (offset != -1)		/* offset found */
    {
      if (print_offset)		/* only print the offset */
	printf("%ji\n", offset);
      else			/* extract using libarchive */
	{
	  struct archive_entry *entry;
	  int status;

	  unmakeself_lseek(fd, offset, SEEK_SET);

	  archive = archive_read_new();

	  if (archive_read_support_compression_all(archive) != ARCHIVE_OK)
	    fprintf(stderr, "%s: warning: unable to support all compression formats: %s\n", self, archive_error_string(archive));
	  if (archive_read_support_format_all(archive) != ARCHIVE_OK)
	    fprintf(stderr, "%s: warning: unable to support all archive formats: %s\n", self, archive_error_string(archive));

	  /* same block size as DEFAULT_BYTES_PER_BLOCK in bsdtar.h */
	  unmakeself_handle_libarchive_result(archive_read_open_fd(archive, fd, 20 * 512), "archive_read_open_fd");

	  while ((status = archive_read_next_header(archive, &entry)) == ARCHIVE_OK)
	    unmakeself_handle_libarchive_result(archive_read_extract(archive, entry, extract_flags), "archive_read_extract");

	  unmakeself_handle_libarchive_result_full(status == ARCHIVE_EOF, "archive_read_next_header");

	  unmakeself_handle_libarchive_result(archive_read_close(archive), "archive_read_close");

	  archive_read_finish(archive);
	}
    }
  else				/* offset not found */
    unmakeself_error(NULL, "invalid Makeself archive");

  unmakeself_handle_libc_result(close(fd), "close");
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

  filename = argv[0];
  unmakeself_extract(print_offset);

  /* on some systems, the return value of main() is ignored */
  exit(0);

  return 0;
}
