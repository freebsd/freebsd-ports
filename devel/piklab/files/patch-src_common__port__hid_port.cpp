--- src/common/port/hid_port.cpp.orig	2012-06-04 07:17:40.000000000 +0900
+++ src/common/port/hid_port.cpp	2012-06-06 23:02:40.000000000 +0900
@@ -7,6 +7,8 @@
  *   the Free Software Foundation; either version 2 of the License, or     *
  *   (at your option) any later version.                                   *
  ***************************************************************************/
+#ifdef __linux
+
 #include "hid_port.h"
 
 #ifdef Q_OS_UNIX
@@ -140,3 +142,5 @@
 }
 
 #endif
+
+#endif
