Put back some non dumb outputter by default

--- cpan/Pod-Perldoc/lib/Pod/Perldoc.pm.orig	2019-03-12 16:47:18 UTC
+++ cpan/Pod-Perldoc/lib/Pod/Perldoc.pm
@@ -486,6 +486,11 @@ sub init_formatter_class_list {
 
   $self->opt_M_with('Pod::Perldoc::ToPod');   # the always-there fallthru
   $self->opt_o_with('text');
+  $self->opt_o_with('man')
+    unless $self->is_mswin32 || $self->is_dos || $self->is_amigaos
+    || !($ENV{TERM} && (
+	($ENV{TERM} || '') !~ /dumb|emacs|none|unknown/i
+      ));
 
   return;
 }
