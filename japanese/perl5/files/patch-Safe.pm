--- ext/Opcode/Safe.pm.orig	Fri Jan 22 10:03:55 1999
+++ ext/Opcode/Safe.pm	Wed Oct  1 23:08:23 2003
@@ -214,11 +215,11 @@
     # Create anon sub ref in root of compartment.
     # Uses a closure (on $expr) to pass in the code to be executed.
     # (eval on one line to keep line numbers as expected by caller)
-	my $evalcode = sprintf('package %s; sub { eval $expr; }', $root);
+    my $evalcode = sprintf('package %s; sub { @_ = (); eval $expr; }', $root);
     my $evalsub;
 
	if ($strict) { use strict; $evalsub = eval $evalcode; }
	else         {  no strict; $evalsub = eval $evalcode; }
 
     return Opcode::_safe_call_sv($root, $obj->{Mask}, $evalsub);
 }
@@ -228,7 +229,7 @@
     my $root = $obj->{Root};
 
     my $evalsub = eval
-	    sprintf('package %s; sub { do $file }', $root);
+	    sprintf('package %s; sub { @_ = (); do $file }', $root);
     return Opcode::_safe_call_sv($root, $obj->{Mask}, $evalsub);
 }
 
@@ -383,8 +384,9 @@
 This is almost identical to exporting variables using the L<Exporter(3)>
 module.
 
-Each NAME must be the B<name> of a variable, typically with the leading
-type identifier included. A bareword is treated as a function name.
+Each NAME must be the B<name> of a non-lexical variable, typically
+with the leading type identifier included. A bareword is treated as a
+function name.
 
 Examples of legal names are '$foo' for a scalar, '@foo' for an
 array, '%foo' for a hash, '&foo' or 'foo' for a subroutine and '*foo'
@@ -426,7 +428,7 @@
 Any attempt by the code in STRING to use an operator which is not permitted
 by the compartment will cause an error (at run-time of the main program
 but at compile-time for the code in STRING).  The error is of the form
-"%s trapped by operation mask operation...".
+"'%s' trapped by operation mask...".
 
 If an operation is trapped in this way, then the code in STRING will
 not be executed. If such a trapped operation occurs or any other
