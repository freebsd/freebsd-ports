--- cfg_node.c.orig	Sun Jul 28 07:06:03 2002
+++ cfg_node.c	Mon Feb  3 15:15:27 2003
@@ -33,6 +33,7 @@
 #include <stdarg.h>
 #include <unistd.h>
 #include <limits.h>
+#include <sys/types.h>
 
 #include "cfg_main.h"
 #include "cfg_node.h"
@@ -443,8 +444,9 @@
         fprintf(stderr, "step2: child node 0x%lx\n", (unsigned long)node);
         do {
             if (node->token != NULL) {
+                size_t l;
                 token = node->token;
-                size_t l = strlen(token);
+		l = strlen(token);
                 fprintf(stderr, "step2: child node: \"%s\"\n", token);
                 if (   (l == 1 && l == nSel && token[0] == '*')
                     || (l == nSel && strncmp(token, cpSel, nSel) == 0)) {
