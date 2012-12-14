--- cmn/xetp_basic.cpp.orig	2012-05-27 06:52:30.000000000 +0900
+++ cmn/xetp_basic.cpp	2012-05-27 06:53:11.000000000 +0900
@@ -33,7 +33,7 @@
 #include "xetp_basic.h"
 
 
-char *XETPBasic::versionStr = "XETP1.00";
+const char *XETPBasic::versionStr = "XETP1.00";
 // 0.10 released with special RedHat version
 // 0.12 for 2.0b5
 // 0.15 for 2.0b6
