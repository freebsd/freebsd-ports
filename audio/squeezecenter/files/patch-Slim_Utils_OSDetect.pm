
$FreeBSD$

--- Slim/Utils/OSDetect.pm.orig
+++ Slim/Utils/OSDetect.pm
@@ -125,7 +125,7 @@
 
 	if ($detectedOS ne "win") {
 
-		push @paths, (split(/:/, $ENV{'PATH'}), qw(/usr/bin /usr/local/bin /usr/libexec /sw/bin /usr/sbin));
+		push @paths, (split(/:/, $ENV{'PATH'}), qw(/usr/bin /usr/local/bin /usr/local/libexec /usr/libexec /sw/bin /usr/sbin));
 
 	} else {
 
@@ -248,6 +248,48 @@
 			warn "dirsFor: Didn't find a match request: [$dir]\n";
 		}
 
+	} elsif (isFreeBSD()) {
+
+		if ($dir =~ /^(?:Firmware|Graphics|HTML|IR|MySQL|SQL|lib|Bin)$/) {
+
+			push @dirs, "%%PREFIX%%/squeezecenter/$dir";
+
+		} elsif ($dir eq 'Plugins') {
+			push @dirs, "%%SITE_PERL%%", "%%PREFIX%%/squeezecenter/Plugins";
+		
+		} elsif ($dir eq 'strings' || $dir eq 'revision') {
+
+			push @dirs, "%%PREFIX%%/squeezecenter";
+
+		} elsif ($dir eq 'types' || $dir eq 'convert') {
+
+			push @dirs, "%%PREFIX%%/squeezecenter";
+
+		} elsif ($dir eq 'prefs') {
+
+			push @dirs, "%%SLIMDBDIR%%/prefs";
+
+		} elsif ($dir eq 'log') {
+
+			push @dirs, "/var/log/squeezecenter";
+
+		} elsif ($dir eq 'cache') {
+
+			push @dirs, "%%SLIMDBDIR%%/cache";
+
+		} elsif ($dir eq 'MySQL') {
+
+			# Do nothing - use the depended upon MySQL install.
+
+		} elsif ($dir =~ /^(?:music|playlists)$/) {
+
+			push @dirs, '';
+
+		} else {
+
+			warn "dirsFor: Didn't find a match request: [$dir]\n";
+		}
+
 	# Red Hat/Fedora/SUSE RPM specific paths.
 	} elsif (isRHorSUSE()) {
 
@@ -432,6 +474,28 @@
 	return isReadyNAS();
 }
 
+=head2 isFreeBSD( )
+
+ The FreeBSD package has some specific differences for file locations.
+ This routine needs no args, and returns 1 if FreeBSD is detected, with
+ a clear sign that the port/package has been installed, 0 if not.
+
+=cut
+
+sub isFreeBSD {
+
+	# Initialize
+	my $OS      = OS();
+	my $details = details();
+
+	if ($details->{'osName'} eq 'freebsd' && $0 =~ m{^/usr/local/squeezecenter} ) {
+	       return 1;
+	}
+
+	return 0;
+}
+
+
 sub isRHorSUSE {
 
 	# Initialize
