--- lib/VCP/Utils/p4.pm.orig	Fri Jan 30 10:48:39 2004
+++ lib/VCP/Utils/p4.pm	Mon Apr 19 00:35:59 2004
@@ -830,7 +830,7 @@
    $self->p4( [ "client", "-i" ], \$client_spec, \my $out ) ;
 
    die "unexpected stdout from p4:\np4: ", $out
-      unless $out =~ /^Client\s.*\ssaved\./ ;
+      unless $out =~ /^Client\s.*\s(saved|.*not changed)\./ ;
 }
 
 =item split_repo_server
