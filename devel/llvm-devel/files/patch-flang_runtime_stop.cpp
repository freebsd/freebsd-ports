--- flang/runtime/stop.cpp.orig
+++ flang/runtime/stop.cpp
@@ -162,7 +162,7 @@
   // TODO: Need to parse DWARF information to print function line numbers
   constexpr int MAX_CALL_STACK{999};
   void *buffer[MAX_CALL_STACK];
-  int nptrs{backtrace(buffer, MAX_CALL_STACK)};
+  int nptrs{(int)backtrace(buffer, MAX_CALL_STACK)};
 
   if (char **symbols{backtrace_symbols(buffer, nptrs)}) {
     for (int i = 0; i < nptrs; i++) {
