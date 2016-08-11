--- src/common/classes/FpeControl.h.orig	2015-03-27 14:47:01.000000000 +0100
+++ src/common/classes/FpeControl.h	2016-04-02 19:45:10.096583000 +0200
@@ -223,13 +223,13 @@
 	return (!_finite (x) && !isnan(x));
 }
 #else
-#ifndef isinf
+#if !defined(isinf) && !defined(__FreeBSD__)
 template <typename F>
 inline bool isinf(F x)
 {
 	return !isnan(x) && isnan(x - x);
 }
-#endif // isinf
+#endif // isinf || FreeBSD
 #endif // WIN_NT
 
 #endif //CLASSES_FPE_CONTROL_H
