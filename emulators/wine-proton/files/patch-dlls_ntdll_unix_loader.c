Disable for now mallopt feature on FreeBSD

--- dlls/ntdll/unix/loader.c.orig	2026-08-03 08:08:29 UTC
+++ dlls/ntdll/unix/loader.c
@@ -2451,7 +2451,9 @@ static void start_main_thread(void)
     set_thread_teb( teb );
 #endif
 
+#if !defined(__FreeBSD__)
     mallopt( M_PERTURB, 0xff );
+#endif
     init_startup_info();
     *(ULONG_PTR *)&peb->CloudFileFlags = get_image_address();
     set_load_order_app_name( main_wargv[0] );
@@ -2460,7 +2462,9 @@ static void start_main_thread(void)
     load_ntdll();
     load_wow64_ntdll( main_image_info.Machine );
     load_apiset_dll();
+#if !defined(__FreeBSD__)
     mallopt( M_PERTURB, 0 );
+#endif
     server_init_process_done();
 }
 
