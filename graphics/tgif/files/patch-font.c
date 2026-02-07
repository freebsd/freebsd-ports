--- font.c.orig	Sat Jun  9 20:34:29 2007
+++ font.c	Sat Jun  9 20:36:15 2007
@@ -869,10 +869,10 @@
                   (nOdd || ((*psz)&0x80) == nDoubleByte);
                   psz++, nSubStrIndex++) {
                if (nOdd) {
-                  gpszTmpStr16[nDoubleByteIndex].byte2 = (unsigned char)(*psz);
+                  gpszTmpStr16[nDoubleByteIndex].byte2 = (unsigned char)(*psz) & 0x7f;
                   nDoubleByteIndex++;
                } else {
-                  gpszTmpStr16[nDoubleByteIndex].byte1 = (unsigned char)(*psz);
+                  gpszTmpStr16[nDoubleByteIndex].byte1 = (unsigned char)(*psz) & 0x7f;
                }
                nOdd = !nOdd;
             }
@@ -932,10 +932,10 @@
                   (nOdd || ((*psz)&0x80) == nDoubleByte);
                   psz++, nSubStrIndex++) {
                if (nOdd) {
-                  gpszTmpStr16[nDoubleByteIndex].byte2 = (unsigned char)(*psz);
+                  gpszTmpStr16[nDoubleByteIndex].byte2 = (unsigned char)(*psz) & 0x7f;
                   nDoubleByteIndex++;
                } else {
-                  gpszTmpStr16[nDoubleByteIndex].byte1 = (unsigned char)(*psz);
+                  gpszTmpStr16[nDoubleByteIndex].byte1 = (unsigned char)(*psz) & 0x7f;
                }
                nOdd = !nOdd;
             }
@@ -981,10 +981,10 @@
                   (nOdd || ((*psz)&0x80) == nDoubleByte);
                   psz++, nSubStrIndex++) {
                if (nOdd) {
-                  gpszTmpStr16[nDoubleByteIndex].byte2 = (unsigned char)(*psz);
+                  gpszTmpStr16[nDoubleByteIndex].byte2 = (unsigned char)(*psz) & 0x7f;
                   nDoubleByteIndex++;
                } else {
-                  gpszTmpStr16[nDoubleByteIndex].byte1 = (unsigned char)(*psz);
+                  gpszTmpStr16[nDoubleByteIndex].byte1 = (unsigned char)(*psz) & 0x7f;
                }
                nOdd = !nOdd;
             }
