--- rendezvous/mDNS.c-	Fri Aug 12 09:08:40 2005
+++ rendezvous/mDNS.c	Fri Aug 12 09:09:07 2005
@@ -1139,7 +1139,7 @@
 
 #include <stdio.h>
 #include <string.h>
-#include <asm/types.h>
+#include <sys/types.h>
 
 static const struct mDNSprintf_format
 {
