--- ./modules/fastcgi/fastcgi.lisp.orig	Fri Dec  8 08:42:55 2006
+++ ./modules/fastcgi/fastcgi.lisp	Fri Dec  8 08:45:45 2006
@@ -146,7 +146,8 @@
 
 
 ; --------------   "C" functions
-;(c-lines "#include \"fastcgi.h\"~%"); completely wrapped
+(eval-when (compile)
+  (setq ffi:*output-c-functions* t))
 
 ; Our wrappers
 (def-call-out fcgi_getenv       (:arguments (var c-string))               (:return-type c-string))
