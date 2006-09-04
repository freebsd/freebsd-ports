--- safefmt.c.orig	Mon Sep  4 17:28:27 2006
+++ safefmt.c	Mon Sep  4 18:07:39 2006
@@ -489,10 +489,10 @@
         SET_ARGLIST_TYPE(format_arg, type);
     }
 
-    ap = arglist->ap;
+    va_copy(ap, arglist->ap);
     for (x = arglist->current;  x < max_arg;  x++)
         load_argument(x, arglist);
-    arglist->ap = ap;
+    va_copy(arglist->ap, ap);
 
     arglist->max     = max_arg;
     arglist->scanned = 1;
@@ -675,7 +675,7 @@
     arglist.current = 0;
     arglist.max     = 0;
     arglist.scanned = 0;
-    arglist.ap      = ap;
+    va_copy(arglist.ap, ap);
     memset(arglist.list, 0, sizeof(arglist.list));
 
     cs_d = 0;
@@ -683,7 +683,7 @@
     padding = NULL;
     *nbytes = padding_size = 0;
     arglist.current = arglist.max = arglist.scanned = 0;
-    arglist.ap = ap;
+    va_copy(arglist.ap, ap);
     trusted = (ifmt->hdr.flags & SAFESTR_TRUSTED) == SAFESTR_TRUSTED;
 
     for (c = start = ifmt->str;  c < ifmt->str + ifmt->hdr.length;  start = ++c)
