--- src/compat_round.cpp.orig	Fri Jun 25 22:50:04 2004
+++ src/compat_round.cpp	Fri Jun 25 22:50:24 2004
@@ -0,0 +1,255 @@
+/* ====================================================
+ * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
+ *
+ * Developed at SunPro, a Sun Microsystems, Inc. business.
+ * Permission to use, copy, modify, and distribute this
+ * software is freely granted, provided that this notice
+ * is preserved.
+ * ====================================================
+ *
+ * Copyright (c) 2003, Steven G. Kargl
+ * Copyright (c) 2003 Mike Barcroft <mike@FreeBSD.org>
+ * Copyright (c) 2002, 2003 David Schultz <dschultz@uclink.Berkeley.EDU>
+ * All rights reserved.
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ * 1. Redistributions of source code must retain the above copyright
+ *    notice unmodified, this list of conditions, and the following
+ *    disclaimer.
+ * 2. Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in the
+ *    documentation and/or other materials provided with the distribution.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
+ * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
+ * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
+ * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
+ * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
+ * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
+ * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
+ * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
+ * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
+ * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
+ */
+
+#include <math.h>
+
+/* Symbolic constants to classify floating point numbers. */
+#define	COMPAT_FP_INFINITE	0x01
+#define	COMPAT_FP_NAN		0x02
+#define	COMPAT_FP_NORMAL	0x04
+#define	COMPAT_FP_SUBNORMAL	0x08
+#define	COMPAT_FP_ZERO		0x10
+
+#include <sys/endian.h>
+#define	compat_fpclassify(x) \
+    ((sizeof (x) == sizeof (float)) ? compat___fpclassifyf(x) \
+    : (sizeof (x) == sizeof (double)) ? compat___fpclassifyd(x) \
+    : compat___fpclassifyl(x))
+
+union compat_IEEEf2bits {
+	float	f;
+	struct {
+#if _BYTE_ORDER == _LITTLE_ENDIAN
+		unsigned int	man	:23;
+		unsigned int	exp	:8;
+		unsigned int	sign	:1;
+#else /* _BIG_ENDIAN */
+		unsigned int	sign	:1;
+		unsigned int	exp	:8;
+		unsigned int	man	:23;
+#endif
+	} bits;
+};
+
+union compat_IEEEd2bits {
+	double	d;
+	struct {
+#if _BYTE_ORDER == _LITTLE_ENDIAN
+		unsigned int	manl	:32;
+		unsigned int	manh	:20;
+		unsigned int	exp	:11;
+		unsigned int	sign	:1;
+#else /* _BIG_ENDIAN */
+		unsigned int	sign	:1;
+		unsigned int	exp	:11;
+		unsigned int	manh	:20;
+		unsigned int	manl	:32;
+#endif
+	} bits;
+};
+
+#ifdef __alpha__
+union compat_IEEEl2bits {
+	long double	e;
+	struct {
+		unsigned int	manl	:32;
+		unsigned int	manh	:20;
+		unsigned int	exp	:11;
+		unsigned int	sign	:1;
+	} bits;
+};
+#define	compat_mask_nbit_l(u)	((void)0)
+#elif __amd64__
+union compat_IEEEl2bits {
+	long double	e;
+	struct {
+		unsigned int	manl	:32;
+		unsigned int	manh	:32;
+		unsigned int	exp	:15;
+		unsigned int	sign	:1;
+		unsigned int	junkl	:16;
+		unsigned int	junkh	:32;
+	} bits;
+};
+#define	compat_mask_nbit_l(u)	((u).bits.manh &= 0x7fffffff)
+#elif __arm__
+union compat_IEEEl2bits {
+	long double	e;
+	struct {
+		unsigned int	manl	:32;
+		unsigned int	manh	:32;
+		unsigned int	exp	:15;
+		unsigned int	sign	:1;
+		unsigned int	junk	:16;
+	} bits;
+};
+#define	compat_mask_nbit_l(u)	((u).bits.manh &= 0x7fffffff)
+#elif __i386__
+union compat_IEEEl2bits {
+	long double	e;
+	struct {
+		unsigned int	manl	:32;
+		unsigned int	manh	:32;
+		unsigned int	exp	:15;
+		unsigned int	sign	:1;
+		unsigned int	junk	:16;
+	} bits;
+};
+#define	compat_mask_nbit_l(u)	((u).bits.manh &= 0x7fffffff)
+#elif __ia64__
+union compat_IEEEl2bits {
+	long double	e;
+	struct {
+#if _BYTE_ORDER == _LITTLE_ENDIAN
+		unsigned int	manl	:32;
+		unsigned int	manh	:32;
+		unsigned int	exp	:15;
+		unsigned int	sign	:1;
+		unsigned long	junk	:48;
+#else /* _BIG_ENDIAN */
+		unsigned long	junk	:48;
+		unsigned int	sign	:1;
+		unsigned int	exp	:15;
+		unsigned int	manh	:32;
+		unsigned int	manl	:32;
+#endif
+	} bits;
+};
+#define	compat_mask_nbit_l(u)	((u).bits.manh &= 0x7fffffff)
+#elif __powerpc__
+union compat_IEEEl2bits {
+	long double	e;
+	struct {
+		unsigned int		sign	:1;
+		unsigned int		exp	:15;
+		unsigned long long	manh	:48;
+		unsigned long long	manl	:64;
+	} bits;
+};
+#define	compat_mask_nbit_l(u)	((void)0)
+#elif __sparc64__
+union compat_IEEEl2bits {
+	long double	e;
+	struct {
+		unsigned int	sign	:1;
+		unsigned int	exp	:15;
+		unsigned long	manh	:48;
+		unsigned long	manl	:64;
+	} bits;
+};
+#define	compat_mask_nbit_l(u)	((void)0)
+#endif
+
+static int
+compat___fpclassifyf(float f)
+{
+	union compat_IEEEf2bits u;
+
+	u.f = f;
+	if (u.bits.exp == 0) {
+		if (u.bits.man == 0)
+			return (COMPAT_FP_ZERO);
+		return (COMPAT_FP_SUBNORMAL);
+	}
+	if (u.bits.exp == 255) {
+		if (u.bits.man == 0)
+			return (COMPAT_FP_INFINITE);
+		return (COMPAT_FP_NAN);
+	}
+	return (COMPAT_FP_NORMAL);
+}
+
+static int
+compat___fpclassifyd(double d)
+{
+	union compat_IEEEd2bits u;
+
+	u.d = d;
+	if (u.bits.exp == 0) {
+		if ((u.bits.manl | u.bits.manh) == 0)
+			return (COMPAT_FP_ZERO);
+		return (COMPAT_FP_SUBNORMAL);
+	}
+	if (u.bits.exp == 2047) {
+		if ((u.bits.manl | u.bits.manh) == 0)
+			return (COMPAT_FP_INFINITE);
+		return (COMPAT_FP_NAN);
+	}
+	return (COMPAT_FP_NORMAL);
+}
+
+static int
+compat___fpclassifyl(long double e)
+{
+	union compat_IEEEl2bits u;
+
+	u.e = e;
+	if (u.bits.exp == 0) {
+		if ((u.bits.manl | u.bits.manh) == 0)
+			return (COMPAT_FP_ZERO);
+		return (COMPAT_FP_SUBNORMAL);
+	}
+	compat_mask_nbit_l(u);		/* Mask normalization bit if applicable. */
+	if (u.bits.exp == 32767) {
+		if ((u.bits.manl | u.bits.manh) == 0)
+			return (COMPAT_FP_INFINITE);
+		return (COMPAT_FP_NAN);
+	}
+	return (COMPAT_FP_NORMAL);
+}
+
+double
+compat_round(double x)
+{
+	double t;
+	int i;
+
+	i = compat_fpclassify(x);
+	if (i == COMPAT_FP_INFINITE || i == COMPAT_FP_NAN)
+		return (x);
+
+	if (x >= 0.0) {
+		t = ceil(x);
+		if (t - x > 0.5)
+			t -= 1.0;
+		return (t);
+	} else {
+		t = ceil(-x);
+		if (t + x > 0.5)
+			t -= 1.0;
+		return (-t);
+	}
+}
