$FreeBSD$

--- ../../hotspot/src/share/vm/interpreter/bytecodes.hpp	22 Oct 2003 23:05:03 -0000	1.1.1.3
+++ ../../hotspot/src/share/vm/interpreter/bytecodes.hpp	12 Oct 2004 05:27:27 -0000
@@ -6,6 +6,9 @@
  * SUN PROPRIETARY/CONFIDENTIAL.  Use is subject to license terms.
  */
 
+
+#include <limits.h>
+
 // Bytecodes specifies all bytecodes used in the VM and
 // provides utility functions to get bytecode attributes.
 
@@ -236,7 +239,8 @@
     // Platform specific JVM bytecodes
     #include "incls/_bytecodes_pd.hpp.incl"
 
-    number_of_codes
+    number_of_codes,
+    WIDTH_HINT = INT_MAX
   };
 
  private:
