--- rnmp3.c.orig	Fri Jul 18 18:00:43 2003
+++ rnmp3.c	Fri Jul 18 18:02:36 2003
@@ -256,25 +256,21 @@
 
 void usage()
 {
-    printf("rnmp3 %s:
-    
-Usage - pipe names into rnmp3. (\"find | rnmp3 args\")
-    If first parameter starts with -, the following string will be removed
-        from all names if they exist (enclose spaces with \"\")
-    If any other commands are entered, commands will not be executed,
-        just printed
-
-    rnmp3                       Rename
-    rnmp3 test                  Don't rename, just show changes
-    rnmp3 -\"string\"             Rename after removing \"string\"
-    rnmp3 -\"string\" test        Don't rename after removing \"string\"
-    rnmp3 --test test           Rename after removing \"-test\"
-
-    Before - \"1-This is my (file name) man.mp3\"
-    After  - \"01-ThisIsMy-FileName-Man.mp3\"
-
-Suggested uses:
-    find . | rnmp3
+    printf("rnmp3 %s:\n\n\
+Usage - pipe names into rnmp3. (\"find | rnmp3 args\")\n\
+    If first parameter starts with -, the following string will be removed\n\
+        from all names if they exist (enclose spaces with \"\")\n\
+    If any other commands are entered, commands will not be executed,\n\
+        just printed\n\n\
+    rnmp3                       Rename\n\
+    rnmp3 test                  Don't rename, just show changes\n\
+    rnmp3 -\"string\"             Rename after removing \"string\"\n\
+    rnmp3 -\"string\" test        Don't rename after removing \"string\"\n\
+    rnmp3 --test test           Rename after removing \"-test\"\n\n\
+    Before - \"1-This is my (file name) man.mp3\"\n\
+    After  - \"01-ThisIsMy-FileName-Man.mp3\"\n\n\
+Suggested uses:\n\
+    find . | rnmp3\n\
     find . -type f | rnmp3\n", VERSION);
 
     exit(0);
