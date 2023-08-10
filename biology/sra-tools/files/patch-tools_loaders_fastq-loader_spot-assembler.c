--- tools/loaders/fastq-loader/spot-assembler.c.orig	2023-08-08 12:26:35 UTC
+++ tools/loaders/fastq-loader/spot-assembler.c
@@ -1,3 +1,4 @@
+
 /*===========================================================================
  *
  *                            PUBLIC DOMAIN NOTICE
@@ -25,6 +26,9 @@
  */
 
 #include "spot-assembler.h"
+
+// FIXME: Unsure if this is still necessary
+#include <sys/stat.h>
 
 #include <klib/status.h>
 #include <klib/printf.h>
