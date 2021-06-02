--- emacsql-sqlite.el.orig	2018-10-31 17:50:07 UTC
+++ emacsql-sqlite.el
@@ -27,11 +27,7 @@
   (file-name-directory (or load-file-name buffer-file-name))
   "Directory where EmacSQL is installed.")
 
-(defvar emacsql-sqlite-executable
-  (expand-file-name (if (memq system-type '(windows-nt cygwin ms-dos))
-                        "sqlite/emacsql-sqlite.exe"
-                      "sqlite/emacsql-sqlite")
-                    emacsql-sqlite-data-root)
+(defvar emacsql-sqlite-executable "%%PREFIX%%/bin/emacsql-sqlite"
   "Path to the EmacSQL backend (this is not the sqlite3 shell).")
 
 (defvar emacsql-sqlite-reserved
@@ -82,6 +78,7 @@ http://www.sqlite.org/lang_keywords.html")
     (emacsql-wait connection)
     (emacsql connection [:pragma (= busy-timeout $s1)]
              (/ (* emacsql-global-timeout 1000) 2))
+    (emacsql connection [:pragma (= foreign_keys 1)])
     (emacsql-register connection)))
 
 (cl-defun emacsql-sqlite (file &key debug)
@@ -143,11 +140,11 @@ If called with non-nil ASYNC the return value is meani
   (let* ((cc (executable-find "cc"))
          (src (expand-file-name "sqlite" emacsql-sqlite-data-root))
          (files (mapcar (lambda (f) (expand-file-name f src))
-                        '("sqlite3.c" "emacsql.c")))
+                        '("emacsql.c")))
          (cflags (list (format "-I%s" src) (format "-O%d" (or o-level 2))))
          (ldlibs (if (memq system-type '(windows-nt berkeley-unix))
-                     (list "-lm")
-                   (list "-lm" "-ldl")))
+                     (list "-lm" "-lsqlite3")
+                   (list "-lm" "-ldl" "-lsqlite3")))
          (options (emacsql-sqlite-compile-switches))
          (output (list "-o" emacsql-sqlite-executable))
          (arguments (nconc cflags options files ldlibs output)))
