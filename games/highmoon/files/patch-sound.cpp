
$FreeBSD$

--- sound.cpp.orig
+++ sound.cpp
@@ -24,7 +24,7 @@
  ******************************************************************************************/
 
 #include <iostream>
-
+#include <stdlib.h>
 #include "sound.hpp"
 
 Soundset::Sample Soundset::sounds[ NUMBEROFCHANNELS ];
