$FreeBSD$

--- ../../hotspot1.3.1/src/share/vm/interpreter/bytecodes.hpp	11 Jul 2001 21:33:21 -0000	1.1.1.1
+++ ../../hotspot1.3.1/src/share/vm/interpreter/bytecodes.hpp	22 Nov 2004 17:19:42 -0000
@@ -14,6 +14,7 @@
 
 // CopyrightVersion 1.2
 
+#include <limits.h>
 
 // Bytecodes specifies all bytecodes used in the VM and
 // provides utility functions to get bytecode attributes.
@@ -279,7 +280,8 @@
     // Platform specific JVM bytecodes
     #include "incls/_bytecodes_pd.hpp.incl"
 
-    number_of_codes
+    number_of_codes,
+    WIDTH_HINT = INT_MAX
   };
 
  private:
