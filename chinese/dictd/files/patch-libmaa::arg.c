--- libmaa/arg.c.orig	Sat Aug  3 03:43:15 2002
+++ libmaa/arg.c	Mon Oct 27 22:11:11 2003
@@ -216,6 +216,9 @@
       ++pt;
 
    for (last = pt, len = 0; *pt; ++pt, ++len) {
+      if((*pt & 0x80) && pt[1]) {
+        ++pt, ++len;
+      } else
       switch (*pt) {
       case ' ':
       case '\t':
