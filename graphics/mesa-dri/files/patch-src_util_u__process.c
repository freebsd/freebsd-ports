--- src/util/u_process.c.orig	2021-06-30 18:18:56 UTC
+++ src/util/u_process.c
@@ -94,22 +94,13 @@ __getProgramName()
 #    define GET_PROGRAM_NAME() __getProgramName()
 #elif defined(HAVE_PROGRAM_INVOCATION_NAME)
 #    define GET_PROGRAM_NAME() program_invocation_short_name
-#elif defined(__FreeBSD__) && (__FreeBSD__ >= 2)
-#    include <osreldate.h>
-#    if (__FreeBSD_version >= 440000)
-#        define GET_PROGRAM_NAME() getprogname()
-#    endif
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__APPLE__) || defined(ANDROID)
+#    define GET_PROGRAM_NAME() getprogname()
 #elif defined(__NetBSD__)
 #    include <sys/param.h>
 #    if defined(__NetBSD_Version__) && (__NetBSD_Version__ >= 106000100)
 #        define GET_PROGRAM_NAME() getprogname()
 #    endif
-#elif defined(__DragonFly__)
-#    define GET_PROGRAM_NAME() getprogname()
-#elif defined(__APPLE__)
-#    define GET_PROGRAM_NAME() getprogname()
-#elif defined(ANDROID)
-#    define GET_PROGRAM_NAME() getprogname()
 #elif defined(__sun)
 /* Solaris has getexecname() which returns the full path - return just
    the basename to match BSD getprogname() */
