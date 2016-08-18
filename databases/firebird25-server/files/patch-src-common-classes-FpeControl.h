--- src/common/classes/FpeControl.h.orig	2016-06-30 09:34:54 UTC
+++ src/common/classes/FpeControl.h
@@ -223,13 +223,13 @@ inline bool isinf(double x)
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
