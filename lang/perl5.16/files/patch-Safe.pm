--- ext/Opcode/Safe.pm.orig	Mon Apr 21 16:37:46 2003
+++ ext/Opcode/Safe.pm	Mon Apr 21 16:37:52 2003
@@ -3,7 +3,7 @@ package Safe;
 use 5.003_11;
 use strict;
 
-our $VERSION = "2.07";
+$Safe::VERSION = "2.09";
 
 use Carp;
 
@@ -47,7 +47,7 @@ sub new {
     # the whole glob *_ rather than $_ and @_ separately, otherwise
     # @_ in non default packages within the compartment don't work.
     $obj->share_from('main', $default_share);
-    Opcode::_safe_pkg_prep($obj->{Root});
+    Opcode::_safe_pkg_prep($obj->{Root}) if($Opcode::VERSION > 1.04);
     return $obj;
 }
 
@@ -155,7 +155,7 @@ sub share_from {
     my $no_record = shift || 0;
     my $root = $obj->root();
     croak("vars not an array ref") unless ref $vars eq 'ARRAY';
-	no strict 'refs';
+    no strict 'refs';
     # Check that 'from' package actually exists
     croak("Package \"$pkg\" does not exist")
 	unless keys %{"$pkg\::"};
@@ -190,7 +190,7 @@ sub share_record {
 sub share_redo {
     my $obj = shift;
     my $shares = \%{$obj->{Shares} ||= {}};
-	my($var, $pkg);
+    my($var, $pkg);
     while(($var, $pkg) = each %$shares) {
 	# warn "share_redo $pkg\:: $var";
 	$obj->share_from($pkg,  [ $var ], 1);
@@ -214,11 +214,11 @@ sub reval {
     # Create anon sub ref in root of compartment.
     # Uses a closure (on $expr) to pass in the code to be executed.
     # (eval on one line to keep line numbers as expected by caller)
-	my $evalcode = sprintf('package %s; sub { eval $expr; }', $root);
+    my $evalcode = sprintf('package %s; sub { @_ = (); eval $expr; }', $root);
     my $evalsub;
 
-	if ($strict) { use strict; $evalsub = eval $evalcode; }
-	else         {  no strict; $evalsub = eval $evalcode; }
+    if ($strict) { use strict; $evalsub = eval $evalcode; }
+    else         {  no strict; $evalsub = eval $evalcode; }
 
     return Opcode::_safe_call_sv($root, $obj->{Mask}, $evalsub);
 }
@@ -228,7 +228,7 @@ sub rdo {
     my $root = $obj->{Root};
 
     my $evalsub = eval
-	    sprintf('package %s; sub { do $file }', $root);
+	    sprintf('package %s; sub { @_ = (); do $file }', $root);
     return Opcode::_safe_call_sv($root, $obj->{Mask}, $evalsub);
 }
 
@@ -383,8 +383,9 @@ This shares the variable(s) in the argum
 This is almost identical to exporting variables using the L<Exporter>
 module.
 
-Each NAME must be the B<name> of a variable, typically with the leading
-type identifier included. A bareword is treated as a function name.
+Each NAME must be the B<name> of a non-lexical variable, typically
+with the leading type identifier included. A bareword is treated as a
+function name.
 
 Examples of legal names are '$foo' for a scalar, '@foo' for an
 array, '%foo' for a hash, '&foo' or 'foo' for a subroutine and '*foo'
@@ -426,7 +427,7 @@ C<main::> package to the code inside the
 Any attempt by the code in STRING to use an operator which is not permitted
 by the compartment will cause an error (at run-time of the main program
 but at compile-time for the code in STRING).  The error is of the form
-"%s trapped by operation mask operation...".
+"'%s' trapped by operation mask...".
 
 If an operation is trapped in this way, then the code in STRING will
 not be executed. If such a trapped operation occurs or any other
