--- icc_profile_tags.cpp.orig	2017-03-15 08:21:33.000000000 +0000
+++ icc_profile_tags.cpp	2017-03-15 08:21:33.000000000 +0000
@@ -349,12 +349,12 @@
 #   ifdef DEBUG_ICCTAG
     DBG_NUM_S ((int)strchr(txt, 13))
 #   endif
-    while (strchr(txt, 13) > 0) { // \r 013 0x0d
+    while (strchr(txt, 13)) { // \r 013 0x0d
       pos = strchr(txt, 13);
 #     ifdef DEBUG_ICCTAG
       //cout << (int)pos << " "; DBG
 #     endif
-      if (pos > 0) {
+      if (pos) {
         if (*(pos+1) == '\n')
           *pos = ' ';
         else
