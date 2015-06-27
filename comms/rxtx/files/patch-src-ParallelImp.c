--- src/ParallelImp.c.orig	2008-11-27 20:01:48.000000000 +0000
+++ src/ParallelImp.c	2015-05-11 16:52:36.000000000 +0100
@@ -265,9 +265,6 @@
 #if defined(__linux__)
 	return( status & LP_BUSY ? JNI_TRUE : JNI_FALSE );
 #endif
-#if defined(__FreeBSD__)
-	return( status & EBUSY ? JNI_TRUE : JNI_FALSE );
-#endif
 	return(JNI_FALSE);
 }
 /*----------------------------------------------------------
