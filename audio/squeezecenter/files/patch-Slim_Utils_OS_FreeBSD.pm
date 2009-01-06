--- /dev/null	2008-12-22 12:00:01.000000000 -0800
+++ Slim/Utils/OS/FreeBSD.pm	2008-12-22 12:00:05.000000000 -0800
@@ -0,0 +1,82 @@
+package Slim::Utils::OS::FreeBSD;
+
+use strict;
+use base qw(Slim::Utils::OS::Unix);
+
+use Config;
+
+sub initDetails {
+	my $class = shift;
+
+	$class->{osDetails} = $class->SUPER::initDetails();
+	$class->{osDetails}->{'os'} = 'FreeBSD';
+	$class->{osDetails}->{osName} = 'FreeBSD';
+
+	return $class->{osDetails};
+}
+
+sub initSearchPath {
+	my $class = shift;
+
+	$class->SUPER::initSearchPath();
+
+	my @extra_paths = qw(/usr/local/libexec);
+	
+	Slim::Utils::Misc::addFindBinPaths(@extra_paths);
+}
+
+sub dirsFor {
+	my ($class, $dir) = @_;
+
+	my @dirs;
+	
+	if ($dir =~ /^(?:Firmware|Graphics|HTML|IR|MySQL|SQL|lib|Bin)$/) {
+
+		push @dirs, "%%PREFIX%%/squeezecenter/$dir";
+
+	} elsif ($dir eq 'Plugins') {
+
+		push @dirs, "%%SITE_PERL%%", "%%PREFIX%%/squeezecenter/Plugins", "%%PREFIX%%/squeezecenter/Slim/Plugin";
+
+	} elsif ($dir eq 'strings' || $dir eq 'revision') {
+
+		push @dirs, "%%PREFIX%%/squeezecenter";
+
+	} elsif ($dir eq 'types' || $dir eq 'convert') {
+
+		push @dirs, "%%PREFIX%%/squeezecenter";
+
+	} elsif ($dir eq 'prefs') {
+
+		push @dirs, "%%SLIMDBDIR%%/prefs";
+
+	} elsif ($dir eq 'log') {
+
+		push @dirs, "/var/log/squeezecenter";
+
+	} elsif ($dir eq 'cache') {
+
+		push @dirs, "%%SLIMDBDIR%%/cache";
+
+	} elsif ($dir =~ /^(?:libpath|mysql-language)$/) {
+
+		# Do nothing - use the depended upon MySQL install.
+
+	} elsif ($dir eq 'oldprefs') {
+
+		if (-r '/var/db/slimserver/slimserver.conf') {
+
+			push @dirs, '/var/db/slimserver/slimserver.conf';
+
+		}
+
+	} else {
+
+		warn "dirsFor: Didn't find a match request: [$dir]\n";
+
+	}
+
+	return wantarray() ? @dirs : $dirs[0];
+}
+
+1;
