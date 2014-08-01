--- src/osd/sdl/osinline.h.orig
+++ src/osd/sdl/osinline.h
@@ -14,7 +14,7 @@
 //  INLINE FUNCTIONS
 //============================================================
 
-#if defined(__i386__) || defined(__x86_64__)
+#if defined(__i386__) || defined(__amd64__) || defined(__x86_64__)
 
 
 INLINE void ATTR_FORCE_INLINE
