--- lib/Lexical/Var.pm.orig	2023-03-24 10:09:57 UTC
+++ lib/Lexical/Var.pm
@@ -63,7 +63,6 @@ variable for each invocation of a function, use C<my>.
 package Lexical::Var;
 
 { use 5.006; }
-use Lexical::SealRequireHints 0.012;
 use warnings;
 use strict;
 
