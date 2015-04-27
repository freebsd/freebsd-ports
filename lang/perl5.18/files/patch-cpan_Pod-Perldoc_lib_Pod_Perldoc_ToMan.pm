--- cpan/Pod-Perldoc/lib/Pod/Perldoc/ToMan.pm.orig	2014-10-01 01:32:59 UTC
+++ cpan/Pod-Perldoc/lib/Pod/Perldoc/ToMan.pm
@@ -63,7 +63,7 @@ sub init {
 sub _roffer_candidates {
 	my( $self ) = @_;
 
-	if( $self->is_openbsd ) { qw( mandoc groff nroff ) }
+	if( $self->is_freebsd || $self->is_openbsd ) { qw( mandoc groff nroff ) }
 	else                    { qw( groff nroff mandoc ) }
 	}
 
