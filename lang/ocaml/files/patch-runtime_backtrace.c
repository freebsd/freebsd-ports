--- runtime/backtrace.c.orig	2019-08-05 17:32:44 UTC
+++ runtime/backtrace.c
@@ -27,9 +27,6 @@
 #include "caml/backtrace_prim.h"
 #include "caml/fail.h"
 
-/* The table of debug information fragments */
-struct ext_table caml_debug_info;
-
 CAMLexport int32_t caml_backtrace_active = 0;
 CAMLexport int32_t caml_backtrace_pos = 0;
 CAMLexport backtrace_slot * caml_backtrace_buffer = NULL;
