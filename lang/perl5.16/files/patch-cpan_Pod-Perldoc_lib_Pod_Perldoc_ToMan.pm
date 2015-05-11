--- cpan/Pod-Perldoc/lib/Pod/Perldoc/ToMan.pm.orig	2013-03-04 15:16:21 UTC
+++ cpan/Pod-Perldoc/lib/Pod/Perldoc/ToMan.pm
@@ -63,7 +63,7 @@ sub init {
 sub _roffer_candidates {
 	my( $self ) = @_;
 
-	if( $self->is_openbsd ) { qw( mandoc groff nroff ) }
+	if( $self->is_openbsd || $self->is_freebsd ) { qw( mandoc groff nroff ) }
 	else                    { qw( groff nroff mandoc ) }
 	}
 
