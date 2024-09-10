--- emacsql-sqlite.el.orig	2024-09-06 13:42:34 UTC
+++ emacsql-sqlite.el
@@ -35,16 +35,7 @@
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
 
 (defvar emacsql-sqlite-c-compilers '("cc" "gcc" "clang")
@@ -131,12 +122,12 @@ If called with non-nil ERROR, signal an error on failu
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
