--- lib/libimhex/source/helpers/stacktrace.cpp.orig	2023-06-24 11:58:12 UTC
+++ lib/libimhex/source/helpers/stacktrace.cpp
@@ -119,7 +119,7 @@
                 auto count = backtrace(addresses.data(), addresses.size());
                 auto functions = backtrace_symbols(addresses.data(), count);
 
-                for (i32 i = 0; i < count; i++)
+                for (size_t i = 0; i < count; i++)
                     result.push_back(StackFrame { "", functions[i], 0 });
 
                 return result;
