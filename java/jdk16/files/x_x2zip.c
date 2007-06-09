/*
 * Copyright (C) 2007 Greg Lewis. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/types.h>
#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef BUFSIZ
#define BUFSIZ 0x10000
#endif

int
main(int argc, char* argv[]) {
    char *key;
    char *oname;
    char buf[BUFSIZ];
    size_t keylen, olen;
    int ifd, ofd, i, fileoff = 0, bufoff = 0, buflen = 0, eof = 0;
    ssize_t bytes;

    if (argc < 3) {
        errx(1, "Usage: x_x2zip <key> <file>");
    }

    // Key
    key = argv[1];
    keylen = strlen(key);

    // Open input file
    if ((ifd = open(argv[2], O_RDONLY)) == -1) {
        err(1, "Can't open input file %s", argv[2]);
    }

    // Open output file
    olen = strlen(argv[2]) + 5;
    if ((oname = (char *) malloc(olen)) == NULL) {
        err(1, "Can't create output file name");
    }
    if (strlcpy(oname, argv[2], olen) >= olen) {
        err(1, "Can't create output file name");
    }
    if (strlcat(oname, ".zip", olen) >= olen) {
        err(1, "Can't create output file name");
    }
    if ((ofd = open(oname,
                    O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR)) == -1) {
        err(1, "Can't open output file %s", oname);
    }
    free(oname);

    while (!eof) {
        // Read into the buffer
        bufoff = 0;
        buflen = 0;
        while (1) {
            if (buflen >= BUFSIZ) {
                break;
            }
            if ((bytes = read(ifd, buf, BUFSIZ - buflen)) == -1) {
                err(1, "Error reading input file");
            }
            if (!bytes) {
                eof = 1;
                break;
            }
            buflen += bytes;
        }

        // Decrypt
        for (i = 0; i < buflen; i++) {
            buf[i] = buf[i] ^ key[(fileoff + i) % keylen];
        }

        // Update file offset
        fileoff += buflen;

        // Output the buffer
        bufoff = 0;
        while (bufoff < buflen) {
            if ((bytes = write(ofd, buf + bufoff, buflen - bufoff)) == -1) {
                err(1, "Error writing output file");
            }
            bufoff += bytes;
        }
    }

    return 0;
}
