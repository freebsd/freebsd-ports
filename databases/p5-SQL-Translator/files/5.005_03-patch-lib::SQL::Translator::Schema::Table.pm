--- lib/SQL/Translator/Schema/Table.pm.orig	Sun May  9 19:09:06 2004
+++ lib/SQL/Translator/Schema/Table.pm	Sun May  9 19:09:30 2004
@@ -104,7 +104,7 @@
     my $constraint_class = 'SQL::Translator::Schema::Constraint';
     my $constraint;
 
-    if ( UNIVERSAL::isa( $_[0], $constraint_class ) ) {
+    if ( UNIVERSAL::isa( $_[0]||'', $constraint_class ) ) {
         $constraint = shift;
         $constraint->table( $self );
     }
