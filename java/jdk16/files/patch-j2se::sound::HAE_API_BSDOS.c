--- ../../j2se/src/solaris/native/com/sun/media/sound/engine/HAE_API_BSDOS.c
+++ ../../j2se/src/solaris/native/com/sun/media/sound/engine/HAE_API_BSDOS.c
@@ -42,6 +42,7 @@
 #include <errno.h>
 
 #ifdef __FreeBSD__
+#include <sys/param.h>
 #include <sys/soundcard.h>
 #endif
 #if defined(__NetBSD__) || defined(__OpenBSD__)
@@ -67,7 +68,16 @@
 #define FALSE		0
 #endif
 
+#if defined(__FreeBSD__) && (__FreeBSD_version >= 700013)
+static inline void *
+memalign(size_t alignment, size_t size)
+{
+    void *ret;
+    return posix_memalign(&ret, alignment, size) ? NULL : ret;
+}
+#else
 #define memalign(a, b)	valloc(b)
+#endif
 
 // How many audio frames to generate at one time 
 #define HAE_BSD_FRAMES_PER_BLOCK		8
