--- src/ParallelImp.c.orig	2008-11-27 20:01:48 UTC
+++ src/ParallelImp.c
@@ -265,9 +265,6 @@ JNIEXPORT jboolean JNICALL LPRPort(isPri
 #if defined(__linux__)
 	return( status & LP_BUSY ? JNI_TRUE : JNI_FALSE );
 #endif
-#if defined(__FreeBSD__)
-	return( status & EBUSY ? JNI_TRUE : JNI_FALSE );
-#endif
 	return(JNI_FALSE);
 }
 /*----------------------------------------------------------
