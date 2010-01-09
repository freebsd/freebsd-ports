
$FreeBSD$

--- tools/asdf.lisp.orig
+++ tools/asdf.lisp
@@ -564,7 +564,9 @@
 	    (system-source-file (cdr system-pair)))))))
 
 (defvar *central-registry*
-  `((directory-namestring *default-pathname-defaults*))
+  `((directory-namestring *default-pathname-defaults*)
+    "ccl:tools;asdf-install;"
+    "%%LOCALBASE%%/lib/common-lisp/system-registry/")
 "A list of 'system directory designators' ASDF uses to find systems.
 
 A 'system directory designator' is a pathname or a function 
