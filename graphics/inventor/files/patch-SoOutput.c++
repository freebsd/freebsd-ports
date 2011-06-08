--- lib/database/src/so/SoOutput.c++.orig	2011-06-08 14:31:06.000000000 +0200
+++ lib/database/src/so/SoOutput.c++	2011-06-08 14:31:15.000000000 +0200
@@ -1462,7 +1462,7 @@
 
     // Generates a CC warning. Ho hum.
     if (refDict->find((unsigned long) base, ref))
-#if (_MIPS_SZPTR == 64 || __ia64)
+#if (_MIPS_SZPTR == 64 || __ia64 || __amd64__)
         referenceId = (int) ((unsigned long) ref);
 #else
 	referenceId = (int)ref;
