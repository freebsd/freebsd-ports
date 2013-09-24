--- tclmUtil.cxx.orig	2013-09-24 09:20:50.000000000 +0200
+++ tclmUtil.cxx	2013-09-24 09:22:32.000000000 +0200
@@ -31,8 +31,8 @@
 extern "C" {
 #include <tcl.h>
 }
-#include <iostream.h>
-#include <iomanip.h>
+#include <iostream>
+#include <iomanip>
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
@@ -99,12 +99,12 @@
 }
 
 void
-Tclm_PrintData(ostream &buf, const unsigned char *data, long length)
+Tclm_PrintData(std::ostream &buf, const unsigned char *data, long length)
 {
 	long i;
 
-	buf.setf(ios::showbase | ios::internal);
-	buf << hex << setw(4) << setfill('0') << (int)data[0];
+	buf.setf(std::ios::showbase | std::ios::internal);
+	buf << std::hex << std::setw(4) << std::setfill('0') << (int)data[0];
 	for (i = 1; i < length; i++)
-		buf << " " << hex << setw(4) << setfill('0') << (int)data[i];
+		buf << " " << std::hex << std::setw(4) << std::setfill('0') << (int)data[i];
 }
