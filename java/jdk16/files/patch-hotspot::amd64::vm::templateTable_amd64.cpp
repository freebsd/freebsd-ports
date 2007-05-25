--- ../../hotspot/src/cpu/amd64/vm/templateTable_amd64.cpp.orig	Tue Oct 19 14:41:28 2004
+++ ../../hotspot/src/cpu/amd64/vm/templateTable_amd64.cpp	Thu May 24 16:34:33 2007
@@ -3266,7 +3266,7 @@
   // initialize object header only.
   __ bind(initialize_header);
   __ movq(Address(rax, oopDesc::mark_offset_in_bytes()), 
-          (int) markOopDesc::prototype()); // header (address 0x1)
+          (intptr_t) markOopDesc::prototype()); // header (address 0x1)
   __ movq(Address(rax, oopDesc::klass_offset_in_bytes()), rarg1);  // klass
   __ jmp(done);
 
