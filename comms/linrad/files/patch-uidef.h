--- uidef.h.orig	Tue May 18 09:43:30 2004
+++ uidef.h	Thu Jul  8 18:27:42 2004
@@ -1,4 +1,5 @@
-#include <arpa/inet.h>
+#include <sys/types.h>
+#include <netinet/in.h>
 
 #define MAX_FLOWCNT 31
  
