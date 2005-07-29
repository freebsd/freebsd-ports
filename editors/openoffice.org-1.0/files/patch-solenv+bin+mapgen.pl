--- solenv/bin/mapgen.pl.orig	Sat Jul 20 22:30:21 2002
+++ solenv/bin/mapgen.pl	Sat Jul 20 22:31:31 2002
@@ -112,7 +112,7 @@
 
 if ($ENV{OS} eq 'SOLARIS') {
 	&gen_sol;
-} elsif ($ENV{OS} eq 'LINUX') {
+} elsif ($ENV{OS} eq 'LINUX' || $ENV{OS} eq 'FREEBSD') {
 	&gen_lnx;
 } else {
 	&print_error ('Environment not set!!');
@@ -169,7 +169,8 @@
 		s/\n//;
 		$env_section = '1' and next if ((/^# SOLARIS #$/) && ($ENV{OS} eq 'SOLARIS'));
 		$env_section = '1' and next if ((/^# LINUX #$/) && ($ENV{OS} eq 'LINUX'));
-		last if ($env_section && ((/^# SOLARIS #$/) || (/^# LINUX #$/)));
+		$env_section = '1' and next if ((/^# FREEBSD #$/) && ($ENV{OS} eq 'FREEBSD'));
+		last if ($env_section && ((/^# SOLARIS #$/) || (/^# LINUX #$/) || (/^# FREEBSD #$/)));
 		next if (!$_ || /^#/);
 		push(@filters, $_);
 	};
