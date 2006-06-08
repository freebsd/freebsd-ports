Submitted By:            Randy McMurchy <randy_at_linuxfromscratch_dot_org>
Date:                    2005-10-04
Initial Package Version: 1.6.7
Upstream Status:         Unknown
Origin:                  http://article.gmane.org/gmane.comp.gnome.apps.gnucash.devel/13956
Description:             Fixes Guile with SLIB >= 3a2

diff -Naur guile-1.6.7-orig/ice-9/slib.scm guile-1.6.7/ice-9/slib.scm
--- ice-9/slib.scm	2004-08-11 20:04:21.000000000 -0500
+++ ice-9/slib.scm	2005-10-04 19:48:04.000000000 -0500
@@ -388,3 +388,74 @@
 
 (define (make-exchanger obj)
   (lambda (rep) (let ((old obj)) (set! obj rep) old)))
+
+(define software-type
+  (if (string<? (version) "1.6")
+      (lambda () 'UNIX)
+      (lambda () 'unix)))
+
+(define (user-vicinity)
+  (case (software-type)
+    ((VMS)	"[.]")
+    (else	"")))
+
+(define vicinity:suffix?
+  (let ((suffi
+	 (case (software-type)
+	   ((amiga)				'(#\: #\/))
+	   ((macos thinkc)			'(#\:))
+	   ((ms-dos windows atarist os/2)	'(#\\ #\/))
+	   ((nosve)				'(#\: #\.))
+	   ((unix coherent plan9)		'(#\/))
+	   ((vms)				'(#\: #\]))
+	   (else
+	    (warn "require.scm" 'unknown 'software-type (software-type))
+	    "/"))))
+    (lambda (chr) (and (memv chr suffi) #t))))
+
+(define (pathname->vicinity pathname)
+  (let loop ((i (- (string-length pathname) 1)))
+    (cond ((negative? i) "")
+	  ((vicinity:suffix? (string-ref pathname i))
+	   (substring pathname 0 (+ i 1)))
+	  (else (loop (- i 1))))))
+
+(define (program-vicinity)
+  (define clp (current-load-port))
+  (if clp
+      (pathname->vicinity (port-filename clp))
+      (slib:error 'program-vicinity " called; use slib:load to load")))
+
+(define sub-vicinity
+  (case (software-type)
+    ((VMS) (lambda
+	       (vic name)
+	     (let ((l (string-length vic)))
+	       (if (or (zero? (string-length vic))
+		       (not (char=? #\] (string-ref vic (- l 1)))))
+		   (string-append vic "[" name "]")
+		   (string-append (substring vic 0 (- l 1))
+				  "." name "]")))))
+    (else (let ((*vicinity-suffix*
+		 (case (software-type)
+		   ((NOSVE) ".")
+		   ((MACOS THINKC) ":")
+		   ((MS-DOS WINDOWS ATARIST OS/2) "\\")
+		   ((unix COHERENT PLAN9 AMIGA) "/"))))
+	    (lambda (vic name)
+	      (string-append vic name *vicinity-suffix*))))))
+
+(define with-load-pathname
+  (let ((exchange
+	 (lambda (new)
+	   (let ((old program-vicinity))
+	     (set! program-vicinity new)
+	     old))))
+    (lambda (path thunk)
+      (define old #f)
+      (define vic (pathname->vicinity path))
+      (dynamic-wind
+	  (lambda () (set! old (exchange (lambda () vic))))
+	  thunk
+	  (lambda () (exchange old))))))
+
