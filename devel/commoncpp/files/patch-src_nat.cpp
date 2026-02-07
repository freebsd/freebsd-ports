--- src/nat.cpp	2013-03-23 23:47:39.000000000 -0500
+++ src/nat.cpp	2013-03-23 23:47:54.000000000 -0500
@@ -42,6 +42,7 @@
  **/
 
 #include <cc++/config.h>
+#include <net/if.h>
 #include "nat.h"
 
 #ifdef CCXX_NAT
