--- test/src/treesit-tests.el.orig	2025-01-04 11:05:31 UTC
+++ test/src/treesit-tests.el
@@ -434,10 +434,10 @@ BODY is the test body."
                ;; String query.
                '("(string) @string
 (pair key: (_) @keyword)
-((_) @bob (#match \"\\\\`B.b\\\\'\" @bob))
+((_) @bob (#match? \"\\\\`B.b\\\\'\" @bob))
 (number) @number
-((number) @n3 (#equal \"3\" @n3))
-((number) @n3p (#pred treesit--ert-pred-last-sibling @n3p))"
+((number) @n3 (#eq? \"3\" @n3))
+((number) @n3p (#pred? treesit--ert-pred-last-sibling @n3p))"
                  ;; Sexp query.
                  ((string) @string
                   (pair key: (_) @keyword)
