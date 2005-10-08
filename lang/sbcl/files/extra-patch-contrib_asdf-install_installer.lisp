--- contrib/asdf-install/installer.lisp.orig	Thu Jul 14 11:30:06 2005
+++ contrib/asdf-install/installer.lisp	Fri Oct  7 00:22:49 2005
@@ -249,8 +249,9 @@
   (let* ((tar
           (with-output-to-string (o)
             (or
-             (sb-ext:run-program #-darwin "tar"
-                                 #+darwin "gnutar"
+             (sb-ext:run-program #+darwin "gnutar"
+ 				 #+freebsd "gtar"
+				 #-(or darwin freebsd) "tar"
                                  (list "-C" (namestring source)
                                        "-xzvf" (namestring packagename))
                                  :output o
