--- src/prefs.cc.orig	Sat Dec  9 16:07:38 2000
+++ src/prefs.cc	Thu Apr  7 20:48:59 2005
@@ -18,6 +18,7 @@
  */
 
 #include <stdlib.h>
+#include <unistd.h>
 
 #include "util.h"
 #include "conffile.h"
@@ -33,9 +34,13 @@
 {
 	if(name.empty())
 		name = getenv("USER");
+		if (name.empty())
+			name = "nobody";
 	
 	if(mail.empty()){
-		char *host = getenv("HOSTNAME");
+		char host[256];
+		if (gethostname(host, 256))
+			strncpy(host, "dev.null.org", 255);
 		mail = name + "@" + host;
 	};
 
