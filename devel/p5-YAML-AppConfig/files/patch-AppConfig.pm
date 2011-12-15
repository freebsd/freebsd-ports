--- lib/YAML/AppConfig.pm.orig	2006-07-09 16:34:56.000000000 +0900
+++ lib/YAML/AppConfig.pm	2011-12-15 10:36:01.945716486 +0900
@@ -2,7 +2,6 @@
 use strict;
 use warnings;
 use Carp;
-use UNIVERSAL qw(isa);
 use Storable qw(dclone);  # For Deep Copy
 
 ####################
@@ -113,7 +112,7 @@
     if ( not ref $value ) {
         $value = $self->_resolve_scalar($value);
     }
-    elsif ( isa $value, 'HASH' ) {
+    elsif (ref $value eq 'HASH' ) {
         $value = dclone($value);
         my @hidden = $self->_push_scope($value);
         for my $key ( keys %$value ) {
@@ -122,13 +121,13 @@
         $self->_pop_scope(@hidden);
         return $value;
     }
-    elsif ( isa $value, 'ARRAY' ) {
+    elsif (ref $value eq 'ARRAY' ) {
         $value = dclone($value);
         for my $item (@$value) {
             $item = $self->_resolve_refs( $item );
         }
     }
-    elsif ( isa $value, 'SCALAR' ) {
+    elsif (ref $value eq 'SCALAR' ) {
         $value = $self->_resolve_scalar($$value);
     } 
     else {
