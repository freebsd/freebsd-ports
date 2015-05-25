--- programs/lz4cli.c.orig	2015-05-07 11:23:39 UTC
+++ programs/lz4cli.c
@@ -473,7 +473,7 @@ int main(int argc, char** argv)
     if (multiple_inputs) input_filename = inFileNames[0], output_filename = (const char*)(inFileNames[0]);
     if(!input_filename) { input_filename=stdinmark; }
 
-    /* Check if input or output are defined as console; trigger an error in this case */
+    /* Check if input is defined as console; trigger an error in this case */
     if (!strcmp(input_filename, stdinmark) && IS_CONSOLE(stdin) ) badusage();
 
     /* Check if benchmark is selected */
