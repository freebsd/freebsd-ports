--- ../../hotspot/src/os_cpu/bsd_i486/vm/os_bsd_i486.cpp.orig	Thu May 24 15:27:43 2007
+++ ../../hotspot/src/os_cpu/bsd_i486/vm/os_bsd_i486.cpp	Thu May 24 19:54:47 2007
@@ -238,15 +238,15 @@
   // success, if not we return failure and the caller can retry.
   // 
   _result = false;
-  if (uc->context_eip == (int)_old_addr.pc() ) {
-    uc->context_eip = (int)_new_addr.pc();
+  if (uc->context_eip == (intptr_t)_old_addr.pc() ) {
+    uc->context_eip = (intptr_t)_new_addr.pc();
     _result = true;
 #ifndef __OpenBSD__
   } else if (uc->uc_link != NULL) {
     // Check (and validate) one level of stacked ucontext
     ucontext_t* linked_uc = uc->uc_link;
-    if (os::Bsd::valid_ucontext(thread, uc, linked_uc) && linked_uc->context_eip == (int)_old_addr.pc()) {
-      linked_uc->context_eip = (int)_new_addr.pc();
+    if (os::Bsd::valid_ucontext(thread, uc, linked_uc) && linked_uc->context_eip == (intptr_t)_old_addr.pc()) {
+      linked_uc->context_eip = (intptr_t)_new_addr.pc();
       _result = true;
     }
   }
