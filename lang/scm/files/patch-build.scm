--- build.scm.orig	Wed Nov 27 10:44:43 2002
+++ build.scm	Sat Nov 30 13:16:28 2002
@@ -1438,7 +1438,7 @@
   (lambda (files parms)
     (and (batch:try-chopped-command
 	  parms
-	  "cc" "-O3 -pipe " "-c"
+	  "%%CC%%" "%%CFLAGS%%" "-c"
 	  (c-includes parms)
 	  (c-flags parms)
 	  files)
@@ -1459,7 +1459,7 @@
   (lambda (files parms)
     (and (batch:try-chopped-command
 	  parms
-	  "cc" "-O3 -pipe "
+	  "%%CC%%" "%%CFLAGS%%"
 	  "-fPIC" "-c" (c-includes parms)
 	  (c-flags parms)
 	  files)
@@ -1468,10 +1468,10 @@
 		 (lambda (fname)
 		   (and (batch:try-command
 			 parms
-			 "cc" "-shared"
+			 "%%CC%%" "-shared"
 			 (cond
 			  ((equal? fname "edline") "-lreadline")
-			  ((equal? fname "x") "-L/usr/X11R6/lib -lSM -lICE -lXext -lX11 -lxpg4")
+			  ((equal? fname "x") "-L%%X11BASE%%/lib -lSM -lICE -lXext -lX11")
 			  (else ""))
 			 "-o"
 			 (string-append fname ".so")
@@ -1485,7 +1485,7 @@
   (lambda (oname objects libs parms)
     (and (batch:try-command
 	  parms
-	  "cc" "-shared" "-o"
+	  "%%CC%%" "-shared" "-o"
 	  (string-append
 	   (car (parameter-list-ref parms 'implvic))
 	   oname ".so")
