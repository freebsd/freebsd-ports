--- system.h.orig	Fri Aug 27 12:16:40 1993
+++ system.h	Tue Dec 28 20:01:38 1999
@@ -788,7 +788,10 @@
 #elif defined( CONVEX )
   #define MAX_PATH          ( _POSIX_PATH_MAX + 1 )
   #define MAX_FILENAME		( 254 + 1 )
-#elif defined( POSIX )
+#elif defined( POSIX ) || defined(__FreeBSD__) || defined( __OpenBSD__ ) || defined( __NetBSD__ )
+  #if defined( __FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+  #include <limits.h>
+  #endif
   #define MAX_PATH          ( _POSIX_PATH_MAX + 1 )
   #define MAX_FILENAME		( NAME_MAX + 1 )
 #elif defined( SVR4 )
@@ -875,7 +878,8 @@
 #if defined( AIX ) || defined( AIX386 ) || defined( AIX370 ) || \
 	defined( BSD386 ) || defined( GENERIC ) || defined( HPUX ) || \
 	defined( IRIX ) || defined( NEXT ) || defined( OSF1 ) || \
-	defined( ULTRIX ) || defined( ULTRIX_OLD ) || defined( UTS4 )
+	defined( ULTRIX ) || defined( ULTRIX_OLD ) || defined( UTS4 ) || \
+	defined( __FreeBSD__ ) || defined(__OpenBSD__) || defined(__NetBSD__)
   #define SPACE_OK		TRUE
 #else
   #define SPACE_OK		FALSE
@@ -948,6 +952,13 @@
 #elif defined( UTS4 )					/* Amdahl UTS4 */
   #define NEED_STRLWR
   #define NEED_STRICMP
+#elif defined( __FreeBSD__ ) || defined(__OpenBSD__) || defined(__NetBSD__)                                   /* Amdahl UTS4 */
+  #include <unistd.h>
+  #define tell(fd) lseek((fd),(off_t)0,SEEK_CUR)
+  #define NEED_STRLWR
+  #define stricmp  strcasecmp
+  #define strnicmp strncasecmp
+  #define USE_TERMCAP
 #elif defined( ESIX )					/* Esix */
   #define NEED_HELP
 #endif /* Various mutation-specific defines */
