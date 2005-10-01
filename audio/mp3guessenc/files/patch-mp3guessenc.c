--- mp3guessenc.c.orig	Sat Oct  1 00:34:43 2005
+++ mp3guessenc.c	Sat Oct  1 00:38:22 2005
@@ -515,6 +515,7 @@
   for(q--;q >= lame_string && *q == 'U';q--) *q = '\0';
 
 LSEX_END:  
+  {}
 }
 
 ///////////////////////////////////////////////////////
@@ -541,7 +542,10 @@
   for(i=0;i<256;i++) lame_string[i] = '\0';
 
   input_file = fopen(argv[1],"rb");
-  if (input_file == NULL) exit(0);
+  if (input_file == NULL) {
+    printf("Usage: mp3guessenc mp3file\n");
+    exit(0);
+  }
 
   fseek(input_file,0,SEEK_END);
   filesize = ftell(input_file);
