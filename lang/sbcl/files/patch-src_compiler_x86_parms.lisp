--- src/compiler/x86/parms.lisp	8 May 2007 10:44:02 -0000	1.68
+++ src/compiler/x86/parms.lisp	1 Jun 2007 08:27:01 -0000
@@ -205,7 +205,7 @@
   (def!constant static-space-end          #x011ff000)
 
   (def!constant dynamic-space-start       #x60000000)
-  (def!constant dynamic-space-end         #xA0000000)
+  (def!constant dynamic-space-end         #x80000000)
 
   (def!constant linkage-table-space-start #x01200000)
   (def!constant linkage-table-space-end   #x012ff000))
