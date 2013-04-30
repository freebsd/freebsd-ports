--- src/lib/cp/lexical.c.orig	2013-05-01 05:15:32.000000000 +0900
+++ src/lib/cp/lexical.c	2013-05-01 05:16:36.000000000 +0900
@@ -145,7 +145,7 @@
         switch (c) {
 	case ' ':
 	case '\t':
-            if (i > 0) {
+            if (paren < 1 && i > 0) {
                 newword;
             }
             break;
