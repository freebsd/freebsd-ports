/*
 * Copyright (c) 2020 Christian Weisgerber <naddy@FreeBSD.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <errno.h>
#include <fcntl.h>
#include <stdarg.h>

/*
 * POSIX mandates that open(symlink, O_NOFOLLOW) fail with errno == ELOOP.
 * FreeBSD chooses to deviate from this, but Got depends on it.
 */
int
open_posix(const char *path, int flags, ...)
{
	va_list ap;
	mode_t mode;
	int ret;

	if (flags & O_CREAT) {
		va_start(ap, flags);
		mode = va_arg(ap, int);
		va_end(ap);
		ret = open(path, flags, mode);
	} else
		ret = open(path, flags);

	if (ret == -1 && (flags & O_NOFOLLOW) && errno == EMLINK)
		errno = ELOOP;

	return (ret);
}

int
openat_posix(int fd, const char *path, int flags, ...)
{
	va_list ap;
	mode_t mode;
	int ret;

	if (flags & O_CREAT) {
		va_start(ap, flags);
		mode = va_arg(ap, int);
		va_end(ap);
		ret = openat(fd, path, flags, mode);
	} else
		ret = openat(fd, path, flags);

	if (ret == -1 && (flags & O_NOFOLLOW) && errno == EMLINK)
		errno = ELOOP;

	return (ret);
}
