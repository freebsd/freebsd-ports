--- src/ftpthread.cpp.orig	Mon Jan 31 14:24:47 2005
+++ src/ftpthread.cpp	Thu Feb  3 00:45:36 2005
@@ -31,6 +31,7 @@
 
 #include <iostream>
 #include <list>
+#include <stdlib.h>
 
 #include "kbconfig.h"
 #include "ftplib.h"
@@ -1226,7 +1227,7 @@
 				loc--;
 			}
 
-			off64_t size = atoll(buffer.substr( sizebegin, datebegin - sizebegin).c_str());
+			off64_t size = strtoll(buffer.substr( sizebegin, datebegin - sizebegin).c_str(), (char **)NULL, 10);
 			
 			filestring.erase();
 			filestring.append(buffer, fileloc, buffer.length() - fileloc);
