
$FreeBSD$

--- lib/Devel/REPL/Meta/Plugin.pm.orig
+++ lib/Devel/REPL/Meta/Plugin.pm
@@ -6,6 +6,7 @@
 
 before 'apply' => sub {
   my ($self, $other) = @_;
+  return unless $other->isa('Devel::REPL');
   if (my $pre = $self->get_method('BEFORE_PLUGIN')) {
     $pre->body->($other, $self);
   }
@@ -13,6 +14,7 @@
 
 after 'apply' => sub {
   my ($self, $other) = @_;
+  return unless $other->isa('Devel::REPL');
   if (my $pre = $self->get_method('AFTER_PLUGIN')) {
     $pre->body->($other, $self);
   }
