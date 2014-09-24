--- src/VBox/Devices/Storage/DevATA.cpp.orig	2014-07-15 13:24:35.000000000 -0400
+++ src/VBox/Devices/Storage/DevATA.cpp	2014-07-16 18:17:03.000000000 -0400
@@ -2479,7 +2479,7 @@
         return 0;
 
     ataH2BE_U16(pbBuf, 0x0); /* feature 0: list of profiles supported */
-    pbBuf[2] = (0 << 2) | (1 << 1) | (1 || 0); /* version 0, persistent, current */
+    pbBuf[2] = (0 << 2) | (1 << 1) | (1 << 0); /* version 0, persistent, current */
     pbBuf[3] = 8; /* additional bytes for profiles */
     /* The MMC-3 spec says that DVD-ROM read capability should be reported
      * before CD-ROM read capability. */
