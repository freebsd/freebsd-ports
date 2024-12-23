--- tools/sandbox/main.c.orig	2024-12-23 04:03:39 UTC
+++ tools/sandbox/main.c
@@ -7,7 +7,7 @@
 // support namespaces / cgroups. We still behave similarly otherwise
 // in order for it to be transparent to the rest of the system.
 #include <stdio.h>
-#include "tools/sandbox/sandbox.h"
+#include "sandbox.h"
 
 int main(int argc, char* argv[]) {
     if (argc < 2) {
