--- build.scm.orig	Fri Jan 25 10:19:37 2002
+++ build.scm	Sun Apr  7 17:20:38 2002
@@ -585,6 +585,7 @@
      (curses darwin "" "" #f () ())
      (regex darwin "" "" #f () ())
 
+     (c freebsd "" "" #f () ())
      (m freebsd "" "-lm" #f () ())
      (curses freebsd "" "-lncurses" "/usr/lib/libncurses.a" () ())
      (regex freebsd "" "-lgnuregex" "" () ())
@@ -1362,7 +1363,7 @@
   (lambda (files parms)
     (and (batch:try-chopped-command
 	  parms
-	  "cc" "-O" "-c"
+	  "%%CC%%" "%%CFLAGS%%" "-c"
 	  (c-includes parms)
 	  (c-flags parms)
 	  files)
@@ -1372,7 +1373,7 @@
     (batch:rename-file parms
 		       oname (string-append oname "~"))
     (and (batch:try-command parms
-			    "cc" "-o" oname
+			    "%%CC%%" "-o" oname "-export-dynamic"
 			    (must-be-first
 			     '("-nostartfiles"
 			       "pre-crt0.o" "crt0.o"
@@ -1381,29 +1382,31 @@
 	 oname)))
 (defcommand compile-dll-c-files freebsd
   (lambda (files parms)
-    (and (batch:try-chopped-command
-	  parms
-	  "cc" "-O" "-fpic" "-c"
-	  (string-append
-	   "-I" (parameter-list-ref parms 'scm-srcdir))
-	  (c-includes parms)
-	  (c-flags parms)
-	  files)
-	 (let ((objs (map c->o files)))
-	   (every
-	    (lambda (f)
-	      (and (batch:try-command
-		    parms "ld" "-Bshareable" f)
-		   (batch:try-command
-		    parms "mv" "a.out" f)))
-	    objs)
-	   objs))))
-
+    (and
+     (batch:try-chopped-command
+      parms
+      "%%CC%%" "%%CFLAGS%%"
+      "-fPIC" "-c" (c-includes parms)
+      (c-flags parms)
+      files)
+     (let* ((results
+	     (map
+	      (lambda (fname)
+		(and (batch:try-command
+		      parms
+		      "%%CC%%" "-shared" "-o"
+		      (string-append fname ".so")
+		      (string-append fname ".o"))
+		     (batch:delete-file
+		      parms (string-append fname ".o"))
+		     (string-append fname ".so")))
+	      (truncate-up-to (map c-> files) #\/))))
+       (and (apply and? results) results)))))
 (defcommand make-dll-archive freebsd
   (lambda (oname objects libs parms)
     (and (batch:try-command
 	  parms
-	  "ld" "-Bshareable" "-o"
+	  "%%CC%%" "-shared" "-o"
 	  (string-append
 	   (car (parameter-list-ref parms 'implvic))
 	   oname ".so")
