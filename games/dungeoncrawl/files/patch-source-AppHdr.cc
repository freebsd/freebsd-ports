--- AppHdr.h.old	Sat Apr  5 14:18:24 2003
+++ AppHdr.h	Sat Apr  5 14:19:31 2003
@@ -153,6 +153,7 @@
     #define PLAIN_TERM
 //#define MULTIUSER
     #include "liblinux.h"
+    #include <string.h>
 
     // The ALTCHARSET may come across as DEC characters/JIS on non-ibm platforms
     #define CHARACTER_SET           0
