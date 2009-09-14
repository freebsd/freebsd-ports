--- lib/DBIx/Class/Schema/Loader/Base.pm.orig	2009-09-14 23:26:50.599067735 +0900
+++ lib/DBIx/Class/Schema/Loader/Base.pm	2009-09-14 23:28:09.491148344 +0900
@@ -317,12 +317,12 @@
     open(my $fh, '<', $real_inc_path)
         or croak "Failed to open '$real_inc_path' for reading: $!";
     $self->_ext_stmt($class,
-        qq|# These lines were loaded from '$real_inc_path' found in \@INC.|
-        .q|# They are now part of the custom portion of this file|
-        .q|# for you to hand-edit.  If you do not either delete|
-        .q|# this section or remove that file from @INC, this section|
-        .q|# will be repeated redundantly when you re-create this|
-        .q|# file again via Loader!|
+         qq|# These lines were loaded from '$real_inc_path' found in \@INC.\n|
+        .qq|# They are now part of the custom portion of this file\n|
+        .qq|# for you to hand-edit.  If you do not either delete\n|
+        .qq|# this section or remove that file from \@INC, this section\n|
+        .qq|# will be repeated redundantly when you re-create this\n|
+        .qq|# file again via Loader!\n|
     );
     while(<$fh>) {
         chomp;
