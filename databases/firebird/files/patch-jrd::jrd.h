--- jrd/jrd.h.orig	Tue May 14 19:01:06 2002
+++ jrd/jrd.h	Tue May 14 19:23:44 2002
@@ -717,7 +717,8 @@
 #ifdef MULTI_THREAD
 #if (defined APOLLO || defined DECOSF || defined NETWARE_386 || \
 	defined NeXT || defined SOLARIS_MT || defined WIN_NT || \
-	defined OS2_ONLY || defined HP10 || defined LINUX || defined DARWIN)
+	defined OS2_ONLY || defined HP10 || defined LINUX || \
+	defined DARWIN || defined FREEBSD)
 #define PLATFORM_GET_THREAD_DATA ((TDBB) THD_get_specific())
 #endif
 #endif
