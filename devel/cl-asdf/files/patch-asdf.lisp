
$FreeBSD$

--- asdf.lisp.orig
+++ asdf.lisp
@@ -630,7 +630,8 @@
             (system-source-file (cdr system-pair)))))))
 
 (defvar *central-registry*
-  `((directory-namestring *default-pathname-defaults*))
+  `((directory-namestring *default-pathname-defaults*)
+     "%%PREFIX%%/lib/common-lisp/system-registry/")
 "A list of 'system directory designators' ASDF uses to find systems.
 
 A 'system directory designator' is a pathname or a function
