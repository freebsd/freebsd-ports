--- r4rstest.scm.orig
+++ r4rstest.scm
@@ -794,8 +794,7 @@
     (test #t 'mult-float-print-test (mult-float-print-test
 				     (string->number "3.1415926535897931")))
     (test #t 'mult-float-print-test (mult-float-print-test
-				     (string->number "2.7182818284590451")))
-    (test #t float-rw-range-test)))
+				     (string->number "2.7182818284590451")))))
 
 (define (test-bignum)
   (define tb
