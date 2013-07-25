
# HG changeset patch
# User never
# Date 1320440131 25200
# Node ID 1feb272af3a704c03d544ef6c606db32049e492c
# Parent 448691f285a54cd944c45c79ff0ba13ec8e3e205
6636110: unaligned stackpointer leads to crash during deoptimization
Reviewed-by: never, kvn
Contributed-by: Andreas Schoesser <andreas.schoesser@sap.com>

--- hotspot/src/cpu/x86/vm/sharedRuntime_x86_64.cpp.orig	Thu Nov 03 04:12:49 2011 -0700
+++ hotspot/src/cpu/x86/vm/sharedRuntime_x86_64.cpp	Fri Nov 04 13:55:31 2011 -0700
@@ -2797,17 +2797,25 @@ void SharedRuntime::generate_deopt_blob(
   // void Deoptimization::unpack_frames(JavaThread* thread, int exec_mode)
 
   // Use rbp because the frames look interpreted now
-  __ set_last_Java_frame(noreg, rbp, NULL);
-
+  // Save "the_pc" since it cannot easily be retrieved using the last_java_SP after we aligned SP.
+  // Don't need the precise return PC here, just precise enough to point into this code blob.
+  address the_pc = __ pc();
+  __ set_last_Java_frame(noreg, rbp, the_pc);
+
+  __ andptr(rsp, -(StackAlignmentInBytes));  // Fix stack alignment as required by ABI
   __ mov(c_rarg0, r15_thread);
   __ movl(c_rarg1, r14); // second arg: exec_mode
   __ call(RuntimeAddress(CAST_FROM_FN_PTR(address, Deoptimization::unpack_frames)));
+  // Revert SP alignment after call since we're going to do some SP relative addressing below
+  __ movptr(rsp, Address(r15_thread, JavaThread::last_Java_sp_offset()));
 
   // Set an oopmap for the call site
-  oop_maps->add_gc_map(__ pc() - start,
+  // Use the same PC we used for the last java frame
+  oop_maps->add_gc_map(the_pc - start,
                        new OopMap( frame_size_in_words, 0 ));
 
-  __ reset_last_Java_frame(true, false);
+  // Clear fp AND pc
+  __ reset_last_Java_frame(true, true);
 
   // Collect return values
   __ movdbl(xmm0, Address(rsp, RegisterSaver::xmm0_offset_in_bytes()));
@@ -2968,7 +2976,10 @@ void SharedRuntime::generate_uncommon_tr
                               // Prolog
 
   // Use rbp because the frames look interpreted now
-  __ set_last_Java_frame(noreg, rbp, NULL);
+  // Save "the_pc" since it cannot easily be retrieved using the last_java_SP after we aligned SP.
+  // Don't need the precise return PC here, just precise enough to point into this code blob.
+  address the_pc = __ pc();
+  __ set_last_Java_frame(noreg, rbp, the_pc);
 
   // Call C code.  Need thread but NOT official VM entry
   // crud.  We cannot block on this call, no GC can happen.  Call should
@@ -2977,14 +2988,17 @@ void SharedRuntime::generate_uncommon_tr
   //
   // BasicType unpack_frames(JavaThread* thread, int exec_mode);
 
+  __ andptr(rsp, -(StackAlignmentInBytes)); // Align SP as required by ABI
   __ mov(c_rarg0, r15_thread);
   __ movl(c_rarg1, Deoptimization::Unpack_uncommon_trap);
   __ call(RuntimeAddress(CAST_FROM_FN_PTR(address, Deoptimization::unpack_frames)));
 
   // Set an oopmap for the call site
-  oop_maps->add_gc_map(__ pc() - start, new OopMap(SimpleRuntimeFrame::framesize, 0));
-
-  __ reset_last_Java_frame(true, false);
+  // Use the same PC we used for the last java frame
+  oop_maps->add_gc_map(the_pc - start, new OopMap(SimpleRuntimeFrame::framesize, 0));
+
+  // Clear fp AND pc
+  __ reset_last_Java_frame(true, true);
 
   // Pop self-frame.
   __ leave();                 // Epilog

