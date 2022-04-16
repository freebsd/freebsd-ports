Index: modules/fdlibm/src/math_private.h
--- modules/fdlibm/src/math_private.h.orig	2022-04-16 01:44:07 UTC
+++ modules/fdlibm/src/math_private.h
@@ -634,6 +634,34 @@ rnint(__double_t x)
 	return ((double)(x + 0x1.8p52) - 0x1.8p52);
 }
 
+#ifdef __i386__
+typedef long double      __double_t;
+#else
+typedef double      __double_t;
+#endif
+typedef __double_t  double_t;
+
+/* This is needed on FreeBSD i386. */
+#if defined(__i386__) && defined(__GNUCLIKE_ASM)
+static __inline int
+irintf(float x)
+{
+	int n;
+
+	__asm("fistl %0" : "=m" (n) : "t" (x));
+	return (n);
+}
+
+static __inline int
+irintd(double x)
+{
+	int n;
+
+	__asm("fistl %0" : "=m" (n) : "t" (x));
+	return (n);
+}
+#endif
+
 /*
  * irint() and i64rint() give the same result as casting to their integer
  * return type provided their arg is a floating point integer.  They can
