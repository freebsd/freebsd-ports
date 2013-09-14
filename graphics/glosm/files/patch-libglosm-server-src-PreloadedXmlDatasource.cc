--- libglosm-server/src/PreloadedXmlDatasource.cc.orig	2011-02-27 18:05:45.000000000 +0300
+++ libglosm-server/src/PreloadedXmlDatasource.cc	2013-09-14 06:33:17.667228216 +0400
@@ -46,6 +46,7 @@
 
 #include <fcntl.h>
 #include <expat.h>
+#include <unistd.h>
 
 #include <cstring>
 #include <stdexcept>
