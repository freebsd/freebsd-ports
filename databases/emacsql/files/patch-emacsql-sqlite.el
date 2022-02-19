--- emacsql-sqlite.el.orig	2022-02-18 15:43:25 UTC
+++ emacsql-sqlite.el
@@ -33,16 +33,7 @@
     "sqlite/emacsql-sqlite")
   "Relative path to emacsql executable.")
 
-(defvar emacsql-sqlite-executable
-  (expand-file-name emacsql-sqlite-executable-path
-                    (if (or (file-writable-p emacsql-sqlite-data-root)
-                            (file-exists-p (expand-file-name
-                                            emacsql-sqlite-executable-path
-                                            emacsql-sqlite-data-root)))
-                        emacsql-sqlite-data-root
-                      (expand-file-name
-                       (concat "emacsql/" emacsql-version)
-                       user-emacs-directory)))
+(defvar emacsql-sqlite-executable "%%PREFIX%%/bin/emacsql-sqlite"
   "Path to the EmacSQL backend (this is not the sqlite3 shell).")
 
 (defvar emacsql-sqlite-reserved
@@ -100,6 +91,7 @@ used.")
     (emacsql-wait connection)
     (emacsql connection [:pragma (= busy-timeout $s1)]
              (/ (* emacsql-global-timeout 1000) 2))
+    (emacsql connection [:pragma (= foreign_keys 1)])
     (emacsql-register connection)))
 
 (cl-defun emacsql-sqlite (file &key debug)
@@ -163,12 +155,12 @@ If called with non-nil ASYNC the return value is meani
                       if path return it))
          (src (expand-file-name "sqlite" emacsql-sqlite-data-root))
          (files (mapcar (lambda (f) (expand-file-name f src))
-                        '("sqlite3.c" "emacsql.c")))
+                        '("emacsql.c")))
          (cflags (list (format "-I%s" src) (format "-O%d" (or o-level 2))))
          (ldlibs (cl-case system-type
                    (windows-nt (list))
-                   (berkeley-unix (list "-lm"))
-                   (otherwise (list "-lm" "-ldl"))))
+                   (berkeley-unix (list "-lm" "-lsqlite3"))
+                   (otherwise (list "-lm" "-ldl" "-lsqlite3"))))
          (options (emacsql-sqlite-compile-switches))
          (output (list "-o" emacsql-sqlite-executable))
          (arguments (nconc cflags options files ldlibs output)))
