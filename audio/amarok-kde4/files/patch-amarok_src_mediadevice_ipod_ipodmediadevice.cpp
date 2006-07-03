
$FreeBSD$

--- amarok/src/mediadevice/ipod/ipodmediadevice.cpp.orig
+++ amarok/src/mediadevice/ipod/ipodmediadevice.cpp
@@ -46,6 +46,7 @@
 #endif
 
 #include <cstdlib>
+#include <unistd.h>
 
 
 // disable if it takes too long for you
