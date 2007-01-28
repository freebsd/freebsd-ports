
$FreeBSD$

--- Bin/build-perl-modules.pl.orig
+++ Bin/build-perl-modules.pl
@@ -24,14 +24,14 @@
 
 # The list of all the packages needed.
 my %packages = (
-	'Compress::Zlib'     => 'Compress-Zlib-1.41.tar.gz',
-	'DBI'                => 'DBI-1.50.tar.gz',
-	'DBD::mysql'         => 'DBD-mysql-3.0002.tar.gz',
-	'Digest::SHA1'       => 'Digest-SHA1-2.11.tar.gz',
-	'HTML::Parser'       => 'HTML-Parser-3.48.tar.gz',
-	'Template'           => 'Template-Toolkit-2.15.tar.gz',
-	'Time::HiRes'        => 'Time-HiRes-1.86.tar.gz',
-	'XML::Parser::Expat' => 'XML-Parser-2.34.tar.gz',
+#	'Compress::Zlib'     => 'Compress-Zlib-1.41.tar.gz',
+#	'DBI'                => 'DBI-1.50.tar.gz',
+#	'DBD::mysql'         => 'DBD-mysql-3.0002.tar.gz',
+#	'Digest::SHA1'       => 'Digest-SHA1-2.11.tar.gz',
+#	'HTML::Parser'       => 'HTML-Parser-3.48.tar.gz',
+#	'Template'           => 'Template-Toolkit-2.15.tar.gz',
+#	'Time::HiRes'        => 'Time-HiRes-1.86.tar.gz',
+#	'XML::Parser::Expat' => 'XML-Parser-2.34.tar.gz',
 	'YAML::Syck'         => 'YAML-Syck-0.64.tar.gz',
 );
 
@@ -57,6 +57,13 @@
 
 		'env' => [qw(DBI-1.50/blib/lib: DBI-1.50/blib/arch)],
 	},
+
+	'XML-Parser-2.34' => {
+		'Makefile.PL' => join(' ', qw(
+			EXPATLIBPATH="%%LOCALBASE%%/lib"
+			EXPATINCPATH="%%LOCALBASE%%/include"
+		)),
+	},
 );
 
 sub main {
@@ -73,28 +80,14 @@
 
 	print "*** Ignore any warnings about AppConfig. ***\n\n";
 
-	print "Please enter a perl binary to use (defaults to /usr/bin/perl)\n";
-	print "This must be the same perl binary that you ran this program with --> ";
-	chomp($perlBinary = <STDIN>);
-
-	$perlBinary ||= '/usr/bin/perl';
+	$perlBinary = '/usr/bin/perl';
 
 	unless (-f $perlBinary && -x $perlBinary) {
 		die "Couldn't find a perl binary. Exiting.\n";
 	}
 
 	# Where does their slimserver live? Try to guess.
-	if (-f 'slimserver.pl' && -d 'CPAN/arch') {
-
-		$slimServerPath = cwd();
-
-	} else {
-
-		print "Please enter the path to your SlimServer directory (ex: /usr/local/slimserver) --> ";
-		chomp($slimServerPath = <STDIN>);
-	}
-
-	$slimServerPath ||= '/usr/local/slimserver';
+	$slimServerPath ||= '%%TMP_SLIMDIR%%';
 
 	unless (-d $slimServerPath) {
 		die "Couldn't find a valid SlimServer path. Exiting.\n";
@@ -109,12 +102,7 @@
 	# This is where the binaries will end up.
 	my $cpanDest = "$slimServerPath/CPAN/arch/$version/$archname/auto";
 
-	# Where do they want the downloads to go?
-	print "Please enter a directory to download files to --> ";
-	chomp($downloadPath = <STDIN>);
-
-	# Default to the current directory.
-	$downloadPath ||= '.';
+	$downloadPath = '%%CPANWRKDIR%%';
 
 	# Remove trailing slash
 	$downloadPath =~ s|^(.+?)/$|$1|;
@@ -127,30 +115,6 @@
 
 	my $pwd = cwd();
 
-	# What do we want to download with?
-	eval { require LWP::Simple };
-
-	# No LWP - try a command line program.
-	if ($@) {
-
-		for my $cmd (qw(curl wget)) {
-
-			if ($downloadUsing = which($cmd)) {
-				last;
-			}
-		}
-
-	} else {
-
-		$downloadUsing = 'lwp';
-	}
-
-	unless ($downloadUsing) {
-		die "Couldn't find any valid downloaders - install LWP, wget or curl.\n";
-	} else {
-		print "Downloads will use $downloadUsing to fetch tarballs.\n";
-	}
-
 	# Only download the packages that were passsed.
 	my @packages = ();
 
@@ -189,30 +153,8 @@
 
 		chdir($pwd) or die "Couldn't change to $pwd : $!";
 
-		print "\nDownloading $package to: $pwd\n";
-
-		# Remove any previous version.
-		unlink $package;
-
-		if ($downloadUsing eq 'lwp') {
-
-			LWP::Simple::getstore("$SOURCE/$package?view=auto", $package);
-
-		} elsif ($downloadUsing =~ /curl$/) {
-
-			`$downloadUsing --silent -o $package $SOURCE/$package?view=auto`;
-
-		} else {
-
-			`$downloadUsing -q -O $package $SOURCE/$package?view=auto`;
-		}
-
-		unless (-r $package) {
-			print "Something looks wrong - I couldn't read $pwd/$package, which I just downloaded.\n";
-		}
-
-		print "Uncompressing..\n";
-		`gzip -d < $package | tar xvf -`;
+		print "\nExtracting $package in: $pwd\n";
+		`tar xfvz %%DISTDIR%%/$package`;
 
 		unlink $package;
 
