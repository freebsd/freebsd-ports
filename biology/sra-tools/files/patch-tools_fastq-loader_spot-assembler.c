--- tools/fastq-loader/spot-assembler.c.orig	2021-06-20 17:00:29 UTC
+++ tools/fastq-loader/spot-assembler.c
@@ -26,6 +26,8 @@
 
 #include "spot-assembler.h"
 
+#include <sys/stat.h>
+
 #include <klib/status.h>
 #include <klib/printf.h>
 
