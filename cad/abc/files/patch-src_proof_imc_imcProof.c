--- src/proof/imc/imcProof.c.orig	2026-11-14 21:51:54 UTC
+++ src/proof/imc/imcProof.c
@@ -37,6 +37,7 @@
 #include "imcInt.h"
 #include <limits.h>
 #include "misc/mem/mem.h"
+#include <sys/types.h>
 #ifdef _WIN32
 #include <windows.h>
 #include <io.h>
