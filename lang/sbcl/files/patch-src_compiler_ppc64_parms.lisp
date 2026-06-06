--- src/compiler/ppc64/parms.lisp.orig
+++ src/compiler/ppc64/parms.lisp
@@ -80,7 +80,9 @@
                               :dynamic-space-start #x1000000000)
 
 (defconstant alien-linkage-table-growth-direction :up)
-(defconstant alien-linkage-table-entry-size #+little-endian 28 #+big-endian 24)
+;; ELFv2 uses a 7-instruction inline jump (28 bytes); the ELFv1 ABI uses
+;; a 3-word function descriptor (24 bytes).
+(defconstant alien-linkage-table-entry-size #-ppc64-elfv1 28 #+ppc64-elfv1 24)
 
 
 (defenum (:start 8)
