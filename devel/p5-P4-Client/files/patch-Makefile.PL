--- ../P4-Client-2.2596/Makefile.PL	Wed Apr 24 17:56:37 2002
+++ Makefile.PL	Tue Sep  2 10:17:51 2003
@@ -68,14 +68,16 @@ before continuing.
 EOF
 
 	# Get the path to the Perforce API
-	my $apipath = "";
-	print( "Where is the Perforce API to be found: " );
-	$apipath = <STDIN>;
-	$apipath =~ s/\n//;
-
-	# Filthy support for ~/ type paths ( NOT ~user/ though! )
-	$apipath =~ s#\~/#$ENV{HOME}/#;
-	$apipath = abs_path( $apipath );
+	my $apiinc = "%%LOCALBASE%%/include/perforce";
+	my $apilib = "%%LOCALBASE%%/lib/perforce";
+	# my $apipath = "";
+	# print( "Where is the Perforce API to be found: " );
+	# $apipath = <STDIN>;
+	# $apipath =~ s/\n//;
+
+	# # Filthy support for ~/ type paths ( NOT ~user/ though! )
+	# $apipath =~ s#\~/#$ENV{HOME}/#;
+	# $apipath = abs_path( $apipath );
 
 	# These two aren't in the hints file because some variant of them is
 	# needed on every OS so it's better to have it visible.
@@ -86,15 +88,15 @@ EOF
 	    foreach my $libset (@$libs )
 	    {
 		push( @{$flags->{LIBS}}, 
-			"-L$apipath -lclient -lrpc -lsupp $libset" );
+			"-L$apilib -lclient -lrpc -lsupp $libset" );
 		print("Added P4 libs to $libset\n" );
 	    }
 	}
 	else
 	{
-	    push( @{$flags->{LIBS}},  "-L$apipath -lclient -lrpc -lsupp" );
+	    push( @{$flags->{LIBS}},  "-L$apilib -lclient -lrpc -lsupp" );
 	}
-	$flags->{ 'INC' }		= "-I$apipath -Ilib";
+	$flags->{ 'INC' }		= "-I$apiinc -Ilib";
 
 
 	# Last thing to do is to get the address of their perforce 
@@ -107,7 +109,7 @@ the tests
 
 EOF
 	print( "Enter the address of your Perforce server: [localhost:1666]: ");
-	my $p4port = <STDIN>;
+	my $p4port = ""; #<STDIN>;
 	$p4port =~ s/\n//;
 	$p4port = "localhost:1666" if ( $p4port =~ /^$/ );
 
