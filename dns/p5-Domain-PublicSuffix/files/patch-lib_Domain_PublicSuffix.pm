--- lib/Domain/PublicSuffix.pm.orig	2024-11-26 01:04:07 UTC
+++ lib/Domain/PublicSuffix.pm
@@ -45,17 +45,19 @@ Domain::PublicSuffix - Parse a domain down to root
 
 =head1 DESCRIPTION
 
-This module utilizes the "effective_tld_names.dat" provided by Mozilla as a way
-to effectively reduce a fully qualified domain name down to the absolute root.
-The Mozilla PublicSuffix file is an open source, fully documented format that
-shows absolute root TLDs, primarily for Mozilla's browser products to be able
-to determine how far a cookie's security boundaries go.
+This module utilizes the "public_suffix_list.dat" or "effective_tld_names.dat"
+provided by Mozilla as a way to effectively reduce a fully qualified domain
+name down to the absolute root.  The Mozilla PublicSuffix file is an open source,
+fully documented format that shows absolute root TLDs, primarily for Mozilla's
+browser products to be able to determine how far a cookie's security boundaries
+go.
 
-This module will attempt to search etc directories in /usr/share/publicsuffix,
-/usr, /usr/local, and /opt/local for the effective_tld_names.dat file. If a file
-is not found, a default file is loaded from Domain::PublicSuffix::Default, which
-is current at the time of the module's release. You can override the data file
-path by giving the new() method a 'data_file' argument.
+This module will attempt to search %%LOCALBASE%%/share/public_suffix_list,
+/usr/share/publicsuffix, /usr, /usr/local, and /opt/local for the
+public_suffix_list.dat or effective_tld_names.dat file. If a file is not found,
+a default file is loaded from Domain::PublicSuffix::Default, which is current at
+the time of the module's release. You can override the data file path by giving
+the new() method a 'data_file' argument.
 
 When creating a new PublicSuffix object, the module will load the data file as
 specified, and use the internal structure to parse each domain sent to the
@@ -101,7 +103,8 @@ Can take a hashref of arguments:
 
 =item data_file 
 
-A fully qualified path, to override the effective_tld_names.dat file.
+A fully qualified path, to override the public_suffix_list.dat or
+effective_tld_names.dat file.
 
 =item use_default 
 
@@ -255,7 +258,7 @@ sub _load_data {
 
 	my $data_stream_ref;
 
-	# Find an effective_tld_names.dat file
+	# Find an public_suffix_list.dat or effective_tld_names.dat file
 	my @tld_lines;
 	my $dat;
 	if ( $self->use_default ) {
@@ -269,21 +272,25 @@ sub _load_data {
 
 	} else {
 		my @paths = (
+			File::Spec->catdir("%%LOCALBASE%%", qw/ share public_suffix_list /),
 			File::Spec->catdir(File::Spec->rootdir, qw/ usr share publicsuffix /),
 			File::Spec->catdir(File::Spec->rootdir, qw/ etc /),
 			File::Spec->catdir(File::Spec->rootdir, qw/ usr etc /),
 			File::Spec->catdir(File::Spec->rootdir, qw/ usr local etc /),
 			File::Spec->catdir(File::Spec->rootdir, qw/ opt local etc /),
 		);
+		FIND_DATA:
 		foreach my $path (@paths) {
-			$path = File::Spec->catfile( $path, "effective_tld_names.dat" );
-			if ( -e $path ) {
-				open( $dat, '<:encoding(UTF-8)', $path )
-					or die "Cannot open \'" . $path . "\': " . $!;
-				@tld_lines = <$dat>;
-				close($dat);
-				$data_stream_ref = \@tld_lines;
-				last;
+			foreach my $file (qw/ public_suffix_list.dat effective_tld_names.dat /) {
+				my $filepath = File::Spec->catfile( $path, $file );
+				if ( -e $filepath ) {
+					open( $dat, '<:encoding(UTF-8)', $filepath )
+						or die "Cannot open \'" . $filepath . "\': " . $!;
+					@tld_lines = <$dat>;
+					close($dat);
+					$data_stream_ref = \@tld_lines;
+					last FIND_DATA;
+				}
 			}
 		}
 	}
