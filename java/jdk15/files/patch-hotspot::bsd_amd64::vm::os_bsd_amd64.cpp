--- ../../hotspot/src/os_cpu/bsd_amd64/vm/os_bsd_amd64.cpp.orig	Thu May 24 15:27:42 2007
+++ ../../hotspot/src/os_cpu/bsd_amd64/vm/os_bsd_amd64.cpp	Thu May 24 16:26:52 2007
@@ -255,15 +255,15 @@
   // success, if not we return failure and the caller can retry.
   // 
   _result = false;
-  if (uc->context_rip == (int)_old_addr.pc() ) {
-    uc->context_rip = (int)_new_addr.pc();
+  if (uc->context_rip == (intptr_t)_old_addr.pc() ) {
+    uc->context_rip = (intptr_t)_new_addr.pc();
     _result = true;
 #ifndef __OpenBSD__
   } else if (uc->uc_link != NULL) {
     // Check (and validate) one level of stacked ucontext
     ucontext_t* linked_uc = uc->uc_link;
-    if (os::Bsd::valid_ucontext(thread, uc, linked_uc) && linked_uc->context_rip == (int)_old_addr.pc()) {
-      linked_uc->context_rip = (int)_new_addr.pc();
+    if (os::Bsd::valid_ucontext(thread, uc, linked_uc) && linked_uc->context_rip == (intptr_t)_old_addr.pc()) {
+      linked_uc->context_rip = (intptr_t)_new_addr.pc();
       _result = true;
     }
 #endif
