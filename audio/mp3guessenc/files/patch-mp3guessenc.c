--- ./mp3guessenc.c.orig	2011-06-21 21:09:47.000000000 +0200
+++ ./mp3guessenc.c	2011-06-21 21:11:00.000000000 +0200
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
@@ -636,7 +640,7 @@
     {
       printf("Cannot find valid mp3 header, scanning failed\n");
       fclose(input_file);
-      return;
+      return(0);
     }
 
   // read VBR tag
@@ -669,7 +673,7 @@
       if (pos == -1) {
 	printf("Cannot find valid mp3 header, scanning failed\n");
 	fclose(input_file);
-	return;
+	return(0);
       }
     }
   }
@@ -705,7 +709,7 @@
 	    "Free format bitstream is not supported.\n"
 	    "Sorry.\n");
     fclose(input_file);
-    return;
+    return(0);
   }
 
   crc = (head >> 16) & 1;
