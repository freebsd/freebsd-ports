--- common.h.orig	2012-05-07 01:48:43 UTC
+++ common.h
@@ -108,6 +108,7 @@ inline T deg2rad(T angle)
 	return angle * M_PI / 180.0;
 }
 
+#if _LIBCPP_STD_VER <= 14
 template <class T>
 inline T clamp(T x, T a, T b)
 {
@@ -118,6 +119,7 @@ inline T clamp(T x, T a, T b)
 	}
 	return x;
 }
+#endif
 
 extern bool isLittleEndian();
 
