--- src/network.cpp.orig	Mon Aug 25 12:17:02 2003
+++ src/network.cpp	Thu Aug 28 20:47:35 2003
@@ -28,6 +28,7 @@
 #include <qsocket.h>
 #include <qstring.h>
 #include <qtextstream.h>
+#include <ctype.h>
 
 #include "network.h"
 
@@ -102,9 +103,9 @@
 	break;
       response += responseLine;
     }
-    guicmd->Write(response);
-  }
-  guicmd->Write(responseLine);
+ guicmd->Write(response.latin1()); 
+}
+guicmd->Write(responseLine.latin1());
 }
 
 void NetworkInterface::sendFile(QString &filename, bool initgame)
