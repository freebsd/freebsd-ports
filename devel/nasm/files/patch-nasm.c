
$FreeBSD$

--- nasm.c.orig
+++ nasm.c
@@ -185,7 +185,7 @@
     /* define some macros dependent of command-line */
     {
 	char temp [64];
-	sprintf (temp, "__OUTPUT_FORMAT__=%s\n", ofmt->shortname);
+	snprintf (temp, sizeof(temp), "__OUTPUT_FORMAT__=%s\n", ofmt->shortname);
 	pp_pre_define (temp);
     }
 
