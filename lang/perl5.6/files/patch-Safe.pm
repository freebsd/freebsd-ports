--- ext/Opcode/Safe.pm.orig	Fri Feb 23 03:57:54 2001
+++ ext/Opcode/Safe.pm	Mon Apr 21 16:24:39 2003
@@ -213,7 +213,7 @@ sub reval {
     # Create anon sub ref in root of compartment.
     # Uses a closure (on $expr) to pass in the code to be executed.
     # (eval on one line to keep line numbers as expected by caller)
-	my $evalcode = sprintf('package %s; sub { eval $expr; }', $root);
+	my $evalcode = sprintf('package %s; sub { @_ = (); eval $expr; }', $root);
     my $evalsub;
 
 	if ($strict) { use strict; $evalsub = eval $evalcode; }
@@ -227,7 +227,7 @@ sub rdo {
     my $root = $obj->{Root};
 
     my $evalsub = eval
-	    sprintf('package %s; sub { do $file }', $root);
+	    sprintf('package %s; sub { @_ = (); do $file }', $root);
     return Opcode::_safe_call_sv($root, $obj->{Mask}, $evalsub);
 }
 
