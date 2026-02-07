--- wrappers/trace.py.orig	2019-12-25 20:28:21 UTC
+++ wrappers/trace.py
@@ -524,7 +524,7 @@ class Tracer:
         print('#    define alloca _alloca')
         print('#  endif')
         print('#else')
-        print('#  include <alloca.h> // alloca')
+        print('#  include <stdlib.h> // alloca')
         print('#endif')
         print()
         print()
