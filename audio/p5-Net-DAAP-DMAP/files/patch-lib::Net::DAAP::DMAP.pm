--- lib/Net/DAAP/DMAP.pm.orig	Sat Aug 21 14:59:26 2004
+++ lib/Net/DAAP/DMAP.pm	Sat Aug 21 15:09:13 2004
@@ -387,7 +387,7 @@
     my $struct = shift;
     my $out = '';
 
-    my %by_name = map { $_->{NAME} => $_ } values %$Types;
+    my %by_name = map { $_->{NAME} => $_ } grep { %$_ } values %$Types;
     for my $pair (@$struct) {
         my ($name, $value) = @$pair;
         # dmap_unpack doesn't populate the name when its decoded
