--- build.scm.orig	Mon Jan 10 00:23:55 2005
+++ build.scm	Wed Jun 29 02:32:25 2005
@@ -1576,7 +1576,7 @@
 	  parms
 ;;; gcc 3.4.2 for FreeBSD does not allow options other than default i.e. -O0 if NO -DGCC_SPARC_BUG - dai 2004-10-30
 	  ;;"cc" "-O3 -pipe -DGCC_SPARC_BUG " "-c"
-	  "cc" "-O3 -pipe " "-c"
+	  "%%CC%%" "%%CFLAGS%%" "-c"
 	  (c-includes parms)
 	  (c-flags parms)
 	  files)
@@ -1586,7 +1586,7 @@
     (batch:rename-file parms
 		       oname (string-append oname "~"))
     (and (batch:try-command parms
-			    "cc" "-o" oname
+			    "%%CC%%" "-o" oname
 			    (must-be-first
 			     '("-nostartfiles"
 			       "pre-crt0.o" "crt0.o"
@@ -1596,14 +1596,14 @@
 (defcommand compile-dll-c-files freebsd
   (lambda (files parms)
     (and (batch:try-chopped-command
-	  parms "cc" "-O3 -pipe " "-fPIC" "-c"
+	  parms "%%CC%%" "%%CFLAGS%%" "-fPIC" "-c"
 	  (c-includes parms) (c-flags parms) files)
 	 (let ((fnames (truncate-up-to (map c-> files) #\/)))
 	   (and (batch:try-command
 		 parms "cc" "-shared"
 		 (cond
 		  ((equal? (car fnames) "edline") "-lreadline")
-		  ((equal? (car fnames) "x") "-L/usr/X11R6/lib -lSM -lICE -lXext -lX11 -lxpg4")
+		  ((equal? (car fnames) "x") "-L%%X11BASE%%/lib -lSM -lICE -lXext -lX11 -lxpg4")
 		  (else ""))
 		 "-o" (string-append (car fnames) ".so")
 		 (map (lambda (fname) (string-append fname ".o")) fnames))
@@ -1616,7 +1616,7 @@
   (lambda (oname objects libs parms)
     (and (batch:try-command
 	  parms
-	  "cc" "-shared" "-o"
+	  "%%CC%%" "-shared" "-o"
 	  (string-append
 	   (car (parameter-list-ref parms 'implvic))
 	   oname ".so")
