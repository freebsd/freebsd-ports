--- ../../hotspot/src/cpu/i486/vm/templateTable_i486.cpp.orig	Tue Oct 19 14:41:33 2004
+++ ../../hotspot/src/cpu/i486/vm/templateTable_i486.cpp	Thu May 24 19:53:09 2007
@@ -2987,7 +2987,7 @@
   // initialize object header only.
   __ bind(initialize_header);
   __ movl(Address(eax, oopDesc::mark_offset_in_bytes ()),
-          (int)markOopDesc::prototype()); // header
+          (intptr_t) markOopDesc::prototype()); // header
   __ popl(ecx);   // get saved klass back in the register.
   __ movl(Address(eax, oopDesc::klass_offset_in_bytes()), ecx);  // klass
   __ jmp(done);
