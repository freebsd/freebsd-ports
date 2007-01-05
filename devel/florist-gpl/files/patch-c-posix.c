--- c-posix.c.orig	Mon Jan  1 17:10:12 2007
+++ c-posix.c	Mon Jan  1 17:12:03 2007
@@ -3049,7 +3049,7 @@
   gheader("POSIX", IEEE_Header);
   ifprintf(fp,"with Ada_Streams;\n");
   ifprintf(fp,"with Interfaces;\n");
-  ifprintf(fp,"package POSIX is\n\n");
+  ifprintf(fp,"package POSIX is\n");
 
 #ifdef LIBS
   /* Generate one pragma Linker_Options per library */
