--- s.scm.orig	Thu Dec  6 04:56:07 2001
+++ s.scm	Thu Dec  6 04:56:26 2001
@@ -252,7 +252,26 @@
 (define hset! hash-set!)
 
 ; General purpose functions
-(load "sgtk/defextern.scm")
+;(load "sgtk/defextern.scm")
+
+(define *lib* "")
+
+(define-macro (extern type name . args)
+  `(make-extfunc *lib* ,type ,(symbol->string name) (quote ,@args)))
+
+; simplified exteral declarator:
+;
+; (define-extern :RETURN-TYPE CFUNC-NAME :ARG1 :ARG2... [. :ANY])
+;
+(define (cname->scheme x)
+  (string->symbol (string-translate (symbol->string x) "_" "-")))
+
+(define-macro (define-extern t n . a)
+; (write
+  `(define ,(cname->scheme n)
+	 (make-extfunc *lib* ,t ,(symbol->string n) (quote ,a))))
+; )
+
 
 ;; (load "repl.scm")
