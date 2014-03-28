--- src/VBox/Devices/Storage/DevAHCI.cpp.orig	2013-11-29 14:23:47.000000000 -0500
+++ src/VBox/Devices/Storage/DevAHCI.cpp	2013-12-13 20:05:56.000000000 -0500
@@ -3242,7 +3242,7 @@
         return 0;
 
     ataH2BE_U16(pbBuf, 0x0); /* feature 0: list of profiles supported */
-    pbBuf[2] = (0 << 2) | (1 << 1) | (1 || 0); /* version 0, persistent, current */
+    pbBuf[2] = (0 << 2) | (1 << 1) | (1 << 0); /* version 0, persistent, current */
     pbBuf[3] = 8; /* additional bytes for profiles */
     /* The MMC-3 spec says that DVD-ROM read capability should be reported
      * before CD-ROM read capability. */
