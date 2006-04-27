Index: contrib/asdf-install/installer.lisp
===================================================================
RCS file: /cvsroot/sbcl/sbcl/contrib/asdf-install/installer.lisp,v
retrieving revision 1.15
diff -u -r1.15 installer.lisp
--- contrib/asdf-install/installer.lisp	12 Jan 2006 13:26:41 -0000	1.15
+++ contrib/asdf-install/installer.lisp	16 Apr 2006 23:07:05 -0000
@@ -264,11 +264,15 @@
                                  :wait t)
              (error "can't untar"))))
          (dummy (princ tar))
+         (pos-start (if (and (>= (length tar) 2)
+                             (string= (subseq tar 0 2) "x "))
+                        2               ; bsdtar
+                        0))             ; GNU tar
          (pos-slash (position #\/ tar))
          (*default-pathname-defaults*
           (merge-pathnames
            (make-pathname :directory
-                          `(:relative ,(subseq tar 0 pos-slash)))
+                          `(:relative ,(subseq tar pos-start pos-slash)))
            source)))
     (declare (ignore dummy))
     (loop for asd in (directory
