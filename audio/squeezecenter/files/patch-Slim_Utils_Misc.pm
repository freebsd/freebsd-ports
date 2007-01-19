
$FreeBSD$

--- Slim/Utils/Misc.pm.orig
+++ Slim/Utils/Misc.pm
@@ -107,7 +107,7 @@
 
 	if (Slim::Utils::OSDetect::OS() ne "win") {
 
-		push @paths, (split(/:/, $ENV{'PATH'}), qw(/usr/bin /usr/local/bin /usr/libexec /sw/bin /usr/sbin));
+		push @paths, (split(/:/, $ENV{'PATH'}), qw(/usr/bin /usr/local/bin /usr/libexec /usr/local/libexec /sw/bin /usr/sbin));
 
 	} else {
 
