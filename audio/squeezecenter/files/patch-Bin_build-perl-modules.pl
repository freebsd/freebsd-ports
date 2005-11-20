
$FreeBSD$

--- Bin/build-perl-modules.pl.orig
+++ Bin/build-perl-modules.pl
@@ -54,6 +54,13 @@
 
 		'env' => [qw(DBI-1.46/blib/lib: DBI-1.46/blib/arch)],
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
@@ -74,28 +81,14 @@
 
 	print "*** Ignore any warnings about AppConfig. ***\n\n";
 
-	print "Please enter a perl binary to use (defaults to /usr/bin/perl)\n";
-	print "This must be the same perl binary that you ran this program with --> ";
-	chomp($perlBinary = <STDIN>);
-
-	$perlBinary ||= '/usr/bin/perl';
+	$perlBinary = '%%PERL%%';
 
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
@@ -107,12 +100,7 @@
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
@@ -125,32 +113,6 @@
 
 	my $pwd = cwd();
 
-	# What do we want to download with?
-	eval { require LWP::Simple };
-
-	# No LWP - try a command line program.
-	if ($@) {
-
-		for my $cmd (qw(curl wget)) {
-
-			system("which $cmd >/dev/null 2>&1");
-
-			unless ($? >> 8) {
-				$downloadUsing = $cmd;
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
 
 	for my $package (@packages) {
 
@@ -161,18 +123,7 @@
 		# Remove any previous version.
 		unlink $package;
 
-		if ($downloadUsing eq 'lwp') {
-
-			LWP::Simple::getstore("$SOURCE/$package?view=auto", $package);
-
-		} elsif ($downloadUsing eq 'curl') {
-
-			`$downloadUsing --silent -o $package $SOURCE/$package?view=auto`;
-
-		} else {
-
-			`$downloadUsing -q -O $package $SOURCE/$package?view=auto`;
-		}
+		`cp %%DISTDIR%%/$package .`;
 
 		unless (-r $package) {
 			print "Something looks wrong - I couldn't read $pwd/$package, which I just downloaded.\n";
