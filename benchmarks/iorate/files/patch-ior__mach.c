--- ior_mach.c.orig	2011-11-03 15:27:58 UTC
+++ ior_mach.c
@@ -41,6 +41,7 @@ static char rcsid[] = "$Header: /home/we
 #include <time.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <sys/time.h>
 
 /*
  * Solaris needs ior_mach.h to be after the above or
@@ -411,6 +411,10 @@ int	ior_dev_lock( ior_config *cfg, long 
     };	
 
 #else
+#if	defined(IOR_LARGE_FILES) && defined(__FreeBSD__)
+#define	IOR_SET_LOCK_FLAG	F_SETLK
+    struct flock d_lock;		/* lock command to run */
+#else
 #ifdef	IOR_LARGE_FILES
 #define	IOR_SET_LOCK_FLAG	F_SETLK64
     struct flock64 d_lock;		/* lock command to run */
@@ -418,6 +422,7 @@ int	ior_dev_lock( ior_config *cfg, long 
 #define	IOR_SET_LOCK_FLAG	F_SETLK
     struct flock d_lock;		/* lock command to run */
 #endif
+#endif
 
     result = 0;				/* all OK so far */
 
@@ -486,6 +491,10 @@ int	ior_dev_unlock( ior_config *cfg, lon
     };	
 
 #else
+#if	defined(IOR_LARGE_FILES) && defined(__FreeBSD__)
+#define	IOR_SET_LOCK_FLAG	F_SETLK
+    struct flock d_lock;		/* lock command to run */
+#else
 #ifdef	IOR_LARGE_FILES
 #define	IOR_SET_LOCK_FLAG	F_SETLK64
     struct flock64 d_lock;		/* lock command to run */
@@ -493,6 +502,7 @@ int	ior_dev_unlock( ior_config *cfg, lon
 #define	IOR_SET_LOCK_FLAG	F_SETLK
     struct flock d_lock;		/* lock command to run */
 #endif
+#endif
 
     result = 0;				/* all OK so far */
 
