--- midimountain/mcOSSIO.cpp	Wed Dec 11 23:35:35 2002
+++ midimountain/mcOSSIO.cpp	Wed Dec 11 23:35:37 2002
@@ -1,13 +1,14 @@
 //=============================================================================
 // implementation class midi IO
 //=============================================================================
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
 #include <fcntl.h>
 #include <string.h>
 #include <iostream.h>
 #include <mcOSSIO.h>
+#include <iomanip>
 
 
 // define static variables:
@@ -464,7 +465,7 @@
 					break;
 
 				default:
-					cout << "unknown EV_TIMING" << hex << buf[i+1];
+					cout << "unknown EV_TIMING" << std::hex << buf[i+1];
 					break;
 				}
 				i += 8;
