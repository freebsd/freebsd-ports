--- src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp.orig	2023-11-10 13:11:41 UTC
+++ src/hotspot/os_cpu/bsd_aarch64/os_bsd_aarch64.cpp
@@ -962,6 +962,7 @@ void os::print_context(outputStream *st, const void *c
 #endif
   }
   st->cr();
+}
 
 void os::print_tos_pc(outputStream *st, const void *context) {
   if (context == NULL) return;
