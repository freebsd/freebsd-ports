https://github.com/battleblow/jdk16u/pull/1

--- src/hotspot/share/adlc/formsopt.cpp.orig	2021-07-23 23:38:59 UTC
+++ src/hotspot/share/adlc/formsopt.cpp
@@ -436,15 +436,20 @@ void AllocClass::output(FILE *fp) {       // Write inf
 //==============================Frame Handling=================================
 //------------------------------FrameForm--------------------------------------
 FrameForm::FrameForm() {
+  _sync_stack_slots = NULL;
+  _inline_cache_reg = NULL;
+  _interpreter_frame_pointer_reg = NULL;
+  _cisc_spilling_operand_name = NULL;
   _frame_pointer = NULL;
   _c_frame_pointer = NULL;
   _alignment = NULL;
+  _return_addr_loc = false;
+  _c_return_addr_loc = false;
   _return_addr = NULL;
   _c_return_addr = NULL;
   _varargs_C_out_slots_killed = NULL;
   _return_value = NULL;
   _c_return_value = NULL;
-  _interpreter_frame_pointer_reg = NULL;
 }
 
 FrameForm::~FrameForm() {
