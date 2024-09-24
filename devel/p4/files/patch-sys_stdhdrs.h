--- sys/stdhdrs.h.orig	2024-09-23 13:23:02 UTC
+++ sys/stdhdrs.h
@@ -527,7 +527,7 @@ extern "C" int socketpair(int, int, int, int*);
 # endif
 
 # if defined(NEED_TIME_HP)
-#    if defined( OS_LINUX )
+#    if defined( OS_LINUX ) || defined( OS_FREEBSD )
 #       define HAVE_CLOCK_GETTIME
 #if defined(__GLIBC__) && defined(__GLIBC_PREREQ)
 #       if ( __GLIBC_PREREQ( 2, 10 ) && \
