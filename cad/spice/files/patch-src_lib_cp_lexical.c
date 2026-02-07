--- src/lib/cp/lexical.c.orig	1993-04-06 00:48:45 UTC
+++ src/lib/cp/lexical.c
@@ -145,7 +145,7 @@ gotchar:
         switch (c) {
 	case ' ':
 	case '\t':
-            if (i > 0) {
+            if (paren < 1 && i > 0) {
                 newword;
             }
             break;
