--- include/mico/os-math.h.orig	Tue Nov 16 22:31:18 2004
+++ include/mico/os-math.h	Tue Nov 16 21:07:40 2004
@@ -291,6 +291,25 @@
 #define	isnan(x)	(fpclassify(x) == FP_NAN)
 #endif
 #endif
+
+#ifndef asinl
+#define asinl asin
+#endif
+#ifndef ldexpl
+#define ldexpl ldexp
+#endif
+#ifndef frexpl
+#define frexpl frexp
+#endif
+#ifndef fmodl
+#define fmodl fmod
+#endif
+#ifndef ceill
+#define ceill ceil
+#endif
+#ifndef floorl
+#define floorl floor
+#endif
 #endif // __FreeBSD__
 
 #include <unistd.h>
