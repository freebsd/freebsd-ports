- workaround for https://github.com/ArthurSonzogni/FTXUI/issues/556

--- cmake/ftxui_fuzzer.cmake.orig	2023-01-14 19:37:42 UTC
+++ cmake/ftxui_fuzzer.cmake
@@ -23,5 +23,5 @@ function(fuzz name)
   )
 endfunction(fuzz)
 
-fuzz(terminal_input_parser_test_fuzzer)
-fuzz(component_fuzzer)
+#fuzz(terminal_input_parser_test_fuzzer)
+#fuzz(component_fuzzer)
