--- source/helpers/utils.cpp.orig	2020-12-06 20:40:57 UTC
+++ source/helpers/utils.cpp
@@ -3,6 +3,8 @@
 #include <cstdio>
 #include <codecvt>
 #include <locale>
+#include <iostream>
+#include <cxxabi.h>
 
 namespace hex {
 
@@ -90,4 +92,16 @@ namespace hex {
         return result;
     }
 
+    std::string demangle(const std::string &mangled_name) {
+        int status = 0;
+        int skip_underscore = mangled_name.find("__") == 0;
+        char *realname = abi::__cxa_demangle(mangled_name.c_str() + skip_underscore,
+                                             0, 0, &status);
+        std::string result{mangled_name};
+        if (status == 0 && realname) {
+            result = realname;
+            std::free(realname);
+        }
+        return result;
+    }
 }
\ No newline at end of file
