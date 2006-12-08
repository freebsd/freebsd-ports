--- rendezvous/Client.c.orig	Fri Dec 16 23:17:02 2005
+++ rendezvous/Client.c	Wed Jul  5 16:32:45 2006
@@ -83,8 +83,9 @@
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
-#include <asm/types.h>
+#include <sys/types.h>
 
+#include "getline.h"
 #include "mDNSClientAPI.h"// Defines the interface to the mDNS core code
 #include "mDNSPosix.h"    // Defines the specific types needed to run mDNS on this platform
 #include "ExampleClientApp.h"
