--- SeScan.c.orig	Mon Dec 29 07:26:24 2003
+++ SeScan.c	Mon Dec 29 07:27:42 2003
@@ -275,8 +275,8 @@
 #ifdef TEST
 main()
 {
-  scSetInputBuf("Just to see if we'\\'re \\n\\033 able to distinguish' words and strings
-\"Also 'quotes' inside strings\" and 'strs \"inside quotes\"'
+  scSetInputBuf("Just to see if we'\\'re \\n\\033 able to distinguish' words and strings\n\
+\"Also 'quotes' inside strings\" and 'strs \"inside quotes\"'\n\
 Not to forget ^S and ^q control ^ chars");
 
   while (lGetWord() != 0);
