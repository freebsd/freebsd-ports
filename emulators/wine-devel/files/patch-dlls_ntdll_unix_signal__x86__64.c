--- dlls/ntdll/unix/signal_x86_64.c.orig	2026-05-29 20:04:32 UTC
+++ dlls/ntdll/unix/signal_x86_64.c
@@ -536,7 +536,7 @@ static LONG syscall_dispatch_enabled = TRUE;
 static UINT64 xstate_extended_features;
 static LONG syscall_dispatch_enabled = TRUE;
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
 static inline struct thread_data *get_current_thread_data(void)
 {
     unsigned long rsp;
