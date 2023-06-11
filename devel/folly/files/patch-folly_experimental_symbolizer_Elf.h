- workaround for https://github.com/facebook/folly/issues/2015

--- folly/experimental/symbolizer/Elf.h.orig	2023-06-10 21:06:02 UTC
+++ folly/experimental/symbolizer/Elf.h
@@ -25,6 +25,7 @@
 #include <initializer_list>
 #include <stdexcept>
 #include <system_error>
+#include <unordered_map>
 #include <unordered_set>
 
 #include <folly/Conv.h>
