--- ../../hotspot/src/cpu/amd64/vm/interpreter_amd64.hpp.orig	Tue Oct 19 14:41:27 2004
+++ ../../hotspot/src/cpu/amd64/vm/interpreter_amd64.hpp	Thu May 24 16:11:07 2007
@@ -53,11 +53,11 @@
   void generate_stack_overflow_check(void);
 
 #ifndef CORE
-  void InterpreterGenerator::generate_counter_incr(
+  void generate_counter_incr(
                 Label* overflow, 
                 Label* profile_method,
                 Label* profile_method_continue);
-  void InterpreterGenerator::generate_counter_overflow(address entry_point);
+  void generate_counter_overflow(address entry_point);
   void generate_run_compiled_code(void);
   void check_for_compiled_code(Label & run_compiled_code);
 #endif
