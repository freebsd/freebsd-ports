--- src/lib/ebus/device.h.orig	2018-12-26 15:38:15 UTC
+++ src/lib/ebus/device.h
@@ -22,6 +22,7 @@
 #include <unistd.h>
 #include <termios.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include <netdb.h>
 #include <iostream>
 #include <fstream>
