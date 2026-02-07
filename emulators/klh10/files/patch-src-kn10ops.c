--- src/kn10ops.c.orig	Thu Sep 28 17:58:10 2006
+++ src/kn10ops.c	Thu Sep 28 17:59:21 2006
@@ -3238,7 +3238,7 @@
 		    register dw10_t d,
 		    register int nmagbits)
 {
-    register qw10_t qw;
+    qw10_t qw;
     dw10_t quot;
     register int qbit;
 
