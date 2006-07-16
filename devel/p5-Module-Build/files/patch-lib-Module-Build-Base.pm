--- lib/Module/Build/Base.pm.orig	Sun Jul 16 04:42:38 2006
+++ lib/Module/Build/Base.pm	Sun Jul 16 16:20:49 2006
@@ -1232,8 +1232,11 @@
 sub compare_versions {
   my $self = shift;
   my ($v1, $op, $v2) = @_;
-  $v1 = Module::Build::Version->new($v1) 
-    unless UNIVERSAL::isa($v1,'Module::Build::Version');
+  #$v1 = Module::Build::Version->new($v1) 
+  #  unless UNIVERSAL::isa($v1,'Module::Build::Version');
+  # for alpha versions - this doesn't cover all cases, but should work for most:
+  $v1 =~ s/_(\d+)\z/$1/;
+  $v2 =~ s/_(\d+)\z/$1/;
 
   my $eval_str = "\$v1 $op \$v2";
   my $result   = eval $eval_str;
