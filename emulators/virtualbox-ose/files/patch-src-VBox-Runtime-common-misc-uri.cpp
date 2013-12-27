--- src/VBox/Runtime/common/misc/uri.cpp.orig	2013-12-18 11:10:34.000000000 -0500
+++ src/VBox/Runtime/common/misc/uri.cpp	2013-12-19 20:57:32.000000000 -0500
@@ -132,7 +132,10 @@
             /* % encoding means the percent sign and exactly 2 hexadecimal
              * digits describing the ASCII number of the character. */
             ++iIn;
-            char szNum[] = { pszString[iIn++], pszString[iIn++], '\0' };
+            char szNum[3];
+            szNum[0] = pszString[iIn++];
+            szNum[1] = pszString[iIn++];
+            szNum[2] = '\0';
             uint8_t u8;
             rc = RTStrToUInt8Ex(szNum, NULL, 16, &u8);
             if (RT_FAILURE(rc))
