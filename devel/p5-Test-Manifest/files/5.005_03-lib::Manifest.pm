--- lib/Manifest.pm.orig	Fri Feb 20 20:11:18 2004
+++ lib/Manifest.pm	Sun Jun  6 16:35:27 2004
@@ -102,17 +102,17 @@
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
 		carp( "test file begins with t/ [$_]" ) if m|^t/|;
 		push @tests, "t/$_" if -e "t/$_";
 		}
-	close $fh;
+	close FH;
 		
 	return wantarray ? @tests : join " ", @tests;
 	}
@@ -131,16 +131,16 @@
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
