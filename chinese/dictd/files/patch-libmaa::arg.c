--- libmaa/arg.c.orig	Wed Jul 17 05:21:04 2002
+++ libmaa/arg.c	Wed Jul 17 05:13:50 2002
@@ -216,6 +216,9 @@
       ++pt;
 
    for (last = pt, len = 0; *pt; ++pt, ++len) {
+     if((*pt & 0x80) && pt[1]) {
+       ++pt, ++len;
+     } else
       switch (*pt) {
       case ' ':
       case '\t':
