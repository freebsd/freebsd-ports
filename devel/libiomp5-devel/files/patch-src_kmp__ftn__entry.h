--- src/kmp_ftn_entry.h.orig	2015-05-08 20:49:21 UTC
+++ src/kmp_ftn_entry.h
@@ -768,9 +768,9 @@ FTN_GET_NUM_DEVICES( void )
     return 0;
 }
 
-#endif // KMP_MIC || KMP_OS_DARWIN
+#endif // KMP_MIC || KMP_OS_DARWIN 
 
-#if ! KMP_OS_LINUX
+#if ! KMP_OS_LINUX && ! KMP_OS_FREEBSD
 
 int FTN_STDCALL
 FTN_IS_INITIAL_DEVICE( void )
