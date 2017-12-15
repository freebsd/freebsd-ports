--- wrappers/trace.py.orig	2017-10-13 17:18:18 UTC
+++ wrappers/trace.py
@@ -521,7 +521,7 @@ class Tracer:
         print '#    define alloca _alloca'
         print '#  endif'
         print '#else'
-        print '#  include <alloca.h> // alloca'
+        print '#  include <stdlib.h> // alloca'
         print '#endif'
         print
         print
