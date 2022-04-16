--- modules/fdlibm/src/math_private.h.orig	2022-04-16 03:20:29 UTC
+++ modules/fdlibm/src/math_private.h
@@ -30,7 +30,9 @@
  * Adapted from https://github.com/freebsd/freebsd-src/search?q=__double_t
  */
 
+#ifndef __FreeBSD__
 typedef double      __double_t;
+#endif
 typedef __double_t  double_t;
 
 /*
@@ -636,6 +638,33 @@ rnint(__double_t x)
  * sometimes be more efficient because no rounding is required.
  */
 #if (defined(amd64) || defined(__i386__)) && defined(__GNUCLIKE_ASM)
+
+#if defined(__i386__)
+static __inline int
+irintf(float x)
+{
+	int n;
+	__asm("fistl %0" : "=m" (n) : "t" (x));
+	return (n);
+}
+
+static __inline int
+irintd(double x)
+{
+	int n;
+	__asm("fistl %0" : "=m" (n) : "t" (x));
+	return (n);
+}
+
+static __inline int
+irintl(long x)
+{
+	int n;
+	__asm("fistl %0" : "=m" (n) : "t" (x));
+	return (n);
+}
+#endif
+
 #define	irint(x)						\
     (sizeof(x) == sizeof(float) &&				\
     sizeof(__float_t) == sizeof(long double) ? irintf(x) :	\
