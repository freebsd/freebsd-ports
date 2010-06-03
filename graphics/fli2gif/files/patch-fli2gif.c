Index: fli2gif.cpp
@@ -43,7 +43,9 @@
 // ******************
 #include <stdio.h>
 #include <stdlib.h>
-#include <malloc.h>
+#ifndef __STDC__
+# include <malloc.h>
+#endif
 #include <string.h>
 #if defined(__TURBOC__) || defined(_MSC_VER)
     #include <conio.h>
@@ -81,7 +83,7 @@
 // ***  Function prototypes  ***
 // *****************************
 void handle_error(int errorcode);
-char *add_extension(char *filename, char *extension, BOOL enforce);
+char *add_extension(char *filename, const char *extension, BOOL enforce);
 
 
 // **************************
@@ -95,7 +97,7 @@
 //############################################################################
 //############################################################################
 //############################################################################
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
     FILE *fp;
     int i, j;
@@ -104,7 +106,7 @@
     // []----------------[]
     // |  Initialization  |
     // []----------------[]
-    printf("FLI2GIF.EXE -- Automatic Flic to Animated GIF convertor, v1.1\n");
+    printf("FLI2GIF -- Automatic Flic to Animated GIF convertor, v1.1\n");
     printf("   by JL Enterprises, 1996.  (Compiled with "
         #if defined(__TURBOC__)
             "Borland"
@@ -117,6 +119,8 @@
             " for Windows"
         #elif defined(__MSDOS__) || defined(_DOS)
             " for MS-DOS"
+        #elif defined(__FreeBSD__)
+            " for FreeBSD"
         #endif    
         ")\n\n");
     {
@@ -389,7 +393,7 @@
 // Takes a user-entered filename and adds the specified extension if an
 // entension is not explicitly stated in the passed filename.  A pointer
 // to a static buffer is returned.
-char *add_extension(char *filename, char *extension, BOOL enforce)
+char *add_extension(char *filename, const char *extension, BOOL enforce)
 {
     static char Path[_MAX_PATH];
 
