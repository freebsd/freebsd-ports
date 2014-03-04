--- src/VBox/NetworkServices/NAT/VBoxNetLwipNAT.cpp.orig	2014-02-25 12:09:19.000000000 -0500
+++ src/VBox/NetworkServices/NAT/VBoxNetLwipNAT.cpp	2014-03-03 14:50:41.000000000 -0500
@@ -73,6 +73,8 @@
 #include <vector>
 #include <string>
 
+#include <stdio.h>
+
 #include "../NetLib/VBoxNetLib.h"
 #include "../NetLib/VBoxNetBaseService.h"
 #include "../NetLib/utils.h"
