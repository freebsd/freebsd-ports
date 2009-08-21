--- newlib/libc/sys/psp/sys/fd_set.h.orig	1970-01-01 02:00:00.000000000 +0200
+++ newlib/libc/sys/psp/sys/fd_set.h	2007-06-01 12:22:26.000000000 +0300
@@ -0,0 +1,69 @@
+/*	$NetBSD: fd_set.h,v 1.1 2005/05/22 12:44:24 kleink Exp $	*/
+
+/*-
+ * Copyright (c) 1992, 1993
+ *	The Regents of the University of California.  All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ * 3. Neither the name of the University nor the names of its contributors
+ *    may be used to endorse or promote products derived from this software
+ *    without specific prior written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
+ * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
+ * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
+ * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
+ * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
+ * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
+ * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
+ * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ *
+ *	from: @(#)types.h	8.4 (Berkeley) 1/21/94
+ */
+
+#ifndef _SYS_FD_SET_H_
+#define	_SYS_FD_SET_H_
+
+#include <sys/socket.h>
+#include <stdint.h>
+
+/*
+ * Implementation dependent defines, hidden from user space. X/Open does not
+ * specify them.
+ */
+#define	__NBBY		8		/* number of bits in a byte */
+typedef uint32_t	__fd_mask;
+
+/* bits per mask */
+#define __NFDBITS	((unsigned int)sizeof(__fd_mask) * __NBBY)
+
+#define	__howmany(x, y)	(((x) + ((y) - 1)) / (y))
+
+#define	FD_SETSIZE	256
+
+typedef	struct fd_set {
+	__fd_mask	fds_bits[__howmany(FD_SETSIZE, __NFDBITS)];
+} fd_set;
+
+#define	FD_SET(n, p)	\
+	((p)->fds_bits[(n) /__NFDBITS] |= (1 << ((n) % __NFDBITS)))
+
+#define	FD_CLR(n, p)	\
+	((p)->fds_bits[(n) /__NFDBITS] &= ~(1 << ((n) % __NFDBITS)))
+
+#define	FD_ISSET(n, p)	\
+	((p)->fds_bits[(n) /__NFDBITS] & (1 << ((n) % __NFDBITS)))
+
+#define	FD_ZERO(p)	(void)__builtin_memset((p), 0, sizeof(*(p)))
+
+#endif /* _SYS_FD_SET_H_ */
