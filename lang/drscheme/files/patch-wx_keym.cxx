diff -ur mred/wxme/wx_keym.cxx mred/wxme/wx_keym.cxx
--- mred/wxme/wx_keym.cxx	2007-08-03 02:56:05.000000000 +1000
+++ mred/wxme/wx_keym.cxx	2007-12-18 17:19:10.000000000 +1100
@@ -512,14 +512,20 @@
     if (i >= MAX_BUF - 1)
       return 0;
     buffer[i] = keyseq[kp];
-    if (buffer[i] < 128)
-      buffer[i] = tolower(buffer[i]);
+    if (buffer[i] < 128) {
+      wxchar t;
+      t = tolower(buffer[i]);
+      buffer[i] = t;
+    }
   }
   buffer[i] = 0;
   code = 0;
   if (buffer[1]) {
-    if (buffer[0] < 128)
-      buffer[0] = tolower(buffer[0]);
+    if (buffer[0] < 128) {
+      wxchar t;
+      t = tolower(buffer[0]);
+      buffer[0] = t;
+    }
     for (i = 0; keylist[i].str; i++) {
       if (!wx_c_strcmp(buffer, keylist[i].str)) {
 	code = keylist[i].code;
