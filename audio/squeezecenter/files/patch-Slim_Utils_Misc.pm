
$FreeBSD$

--- Slim/Utils/Misc.pm.orig
+++ Slim/Utils/Misc.pm
@@ -106,7 +106,7 @@
 
 	if (Slim::Utils::OSDetect::OS() ne "win") {
 
-		push @paths, (split(/:/, $ENV{'PATH'}), qw(/usr/bin /usr/local/bin /sw/bin /usr/sbin));
+		push @paths, (split(/:/, $ENV{'PATH'}), qw(/usr/bin /usr/local/bin /usr/local/libexec /sw/bin /usr/sbin));
 
 	} else {
 
