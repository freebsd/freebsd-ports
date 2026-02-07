--- src/lef.h.orig	2020-03-19 05:44:48 UTC
+++ src/lef.h
@@ -28,7 +28,7 @@ typedef unsigned long  u_long;
 #endif /* _SYS_TYPES_H */
 
 /* Compare functions aren't defined in the Mac's standard library */
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 typedef int (*__compar_fn_t)(const void*, const void*);
 #endif
 
