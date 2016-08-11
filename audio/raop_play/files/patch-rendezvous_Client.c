--- rendezvous/Client.c.orig	2005-12-16 14:17:02 UTC
+++ rendezvous/Client.c
@@ -83,7 +83,7 @@
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
-#include <asm/types.h>
+#include <sys/types.h>
 
 #include "mDNSClientAPI.h"// Defines the interface to the mDNS core code
 #include "mDNSPosix.h"    // Defines the specific types needed to run mDNS on this platform
