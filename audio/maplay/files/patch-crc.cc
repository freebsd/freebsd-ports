--- crc.cc.orig	1994-06-23 12:14:35 UTC
+++ crc.cc
@@ -18,7 +18,7 @@
  *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
-#include <iostream.h>
+#include <iostream>
 #include <stdlib.h>
 #include "crc.h"
 
@@ -32,7 +32,7 @@ void Crc16::add_bits (uint32 bitstring, 
 #ifdef DEBUG
   if (!length)
   {
-    cerr << "Length of bitstring has to be > 0 in Crc16::add_bits()!\n";
+    std::cerr << "Length of bitstring has to be > 0 in Crc16::add_bits()!\n";
     exit (1);
   }
 #endif
