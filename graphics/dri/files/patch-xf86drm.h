--- src/mesa/drivers/dri/dri_client/imports/xf86drm.h.orig	Sun Feb 13 22:44:48 2005
+++ src/mesa/drivers/dri/dri_client/imports/xf86drm.h	Sun Feb 13 22:44:55 2005
@@ -285,7 +285,7 @@
 #define DRM_LOCK_CONT  0x40000000 /**< Hardware lock is contended */
 
 #if defined(__GNUC__) && (__GNUC__ >= 2)
-# if defined(__i386) || defined(__AMD64__)
+# if defined(__i386) || defined(__amd64__)
 				/* Reflect changes here to drmP.h */
 #define DRM_CAS(lock,old,new,__ret)                                    \
 	do {                                                           \
