--- crc.cc.orig	Thu Nov 21 16:44:18 2002
+++ crc.cc	Thu Nov 21 16:44:30 2002
@@ -18,7 +18,7 @@
  *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
-#include <iostream.h>
+#include <iostream>
 #include <stdlib.h>
 #include "crc.h"
 
@@ -32,7 +32,7 @@
 #ifdef DEBUG
   if (!length)
   {
-    cerr << "Length of bitstring has to be > 0 in Crc16::add_bits()!\n";
+    std::cerr << "Length of bitstring has to be > 0 in Crc16::add_bits()!\n";
     exit (1);
   }
 #endif
