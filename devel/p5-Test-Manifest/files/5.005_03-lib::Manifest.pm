--- lib/Manifest.pm.orig	Sun Sep 26 03:42:46 2004
+++ lib/Manifest.pm	Wed Oct 27 16:25:38 2004
@@ -135,11 +135,11 @@
 sub get_t_files()
 	{
 	carp( "$Manifest does not exist!" ) unless -e $Manifest;
-	return unless open my( $fh ), $Manifest;
+	return unless open FH, $Manifest;
 
 	my @tests = ();
 
-	while( <$fh> )
+	while( <FH> )
 		{
 		chomp;
 		s/^\s+|\s+$//g;
@@ -147,7 +147,7 @@
 		carp( "test file begins with t/ [$_]" ) if m|^t/|;
 		push @tests, catfile( "t", $_ ) if -e catfile( "t", $_ );
 		}
-	close $fh;
+	close FH;
 
 	return wantarray ? @tests : join " ", @tests;
 	}
@@ -166,16 +166,16 @@
 sub make_test_manifest()
 	{
 	carp( "t/ directory does not exist!" ) unless -d "t";
-	return unless open my( $fh ), "> $Manifest";
+	return unless open FH, "> $Manifest";
 
 	my $count = 0;
 	while( my $file = glob("t/*.t") )
 		{
 		$file =~ s|^t/||;
-		print $fh "$file\n";
+		print FH "$file\n";
 		$count++;
 		}
-	close $fh;
+	close FH;
 
 	return $count;
 	}
