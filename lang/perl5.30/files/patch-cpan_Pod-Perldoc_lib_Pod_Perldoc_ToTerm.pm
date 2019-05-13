Handle MANWIDTH=tty

--- cpan/Pod-Perldoc/lib/Pod/Perldoc/ToTerm.pm.orig	2017-04-03 07:28:44 UTC
+++ cpan/Pod-Perldoc/lib/Pod/Perldoc/ToTerm.pm
@@ -69,6 +69,8 @@ sub _get_columns_from_manwidth {
 
 	return 0 unless defined $ENV{MANWIDTH};
 
+	if ($ENV{MANWIDTH} eq 'tty') { return 0; }
+
 	unless( $ENV{MANWIDTH} =~ m/\A\d+\z/ ) {
 		$self->warn( "Ignoring non-numeric MANWIDTH ($ENV{MANWIDTH})\n" );
 		return 0;
