--- ior_mach.c_orig	2013-01-27 02:03:38.000000000 +0200
+++ ior_mach.c	2013-01-27 04:52:47.000000000 +0200
@@ -411,6 +411,10 @@
     };	
 
 #else
+#if	defined(IOR_LARGE_FILES) && defined(__FreeBSD__)
+#define	IOR_SET_LOCK_FLAG	F_SETLK
+    struct flock d_lock;		/* lock command to run */
+#else
 #ifdef	IOR_LARGE_FILES
 #define	IOR_SET_LOCK_FLAG	F_SETLK64
     struct flock64 d_lock;		/* lock command to run */
@@ -418,6 +422,7 @@
 #define	IOR_SET_LOCK_FLAG	F_SETLK
     struct flock d_lock;		/* lock command to run */
 #endif
+#endif
 
     result = 0;				/* all OK so far */
 
@@ -486,6 +491,10 @@
     };	
 
 #else
+#if	defined(IOR_LARGE_FILES) && defined(__FreeBSD__)
+#define	IOR_SET_LOCK_FLAG	F_SETLK
+    struct flock d_lock;		/* lock command to run */
+#else
 #ifdef	IOR_LARGE_FILES
 #define	IOR_SET_LOCK_FLAG	F_SETLK64
     struct flock64 d_lock;		/* lock command to run */
@@ -493,6 +502,7 @@
 #define	IOR_SET_LOCK_FLAG	F_SETLK
     struct flock d_lock;		/* lock command to run */
 #endif
+#endif
 
     result = 0;				/* all OK so far */
 
