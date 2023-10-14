--- dlls/ntdll/unix/signal_x86_64.c.orig	2023-07-17 16:05:30.000000000 +0300
+++ dlls/ntdll/unix/signal_x86_64.c	2023-09-03 00:25:39.179645000 +0300
@@ -2832,7 +2832,11 @@ void signal_init_process(void)
 
 void set_thread_teb( TEB *teb )
 {
+#if defined __linux__
     arch_prctl( ARCH_SET_GS, teb );
+#elif defined (__FreeBSD__)
+    amd64_set_gsbase( teb );
+#endif
 }
 
 /***********************************************************************
