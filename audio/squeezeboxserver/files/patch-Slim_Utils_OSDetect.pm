--- Slim/Utils/OSDetect.pm.orig	2008-12-11 14:13:33.000000000 -0800
+++ Slim/Utils/OSDetect.pm	2008-12-22 11:53:19.000000000 -0800
@@ -121,6 +121,11 @@
 				$os = Slim::Utils::OS::Linux->new();
 			}
 	
+		} elsif ($^O =~ /freebsd/i) {
+
+			require Slim::Utils::OS::FreeBSD;
+			$os = Slim::Utils::OS::FreeBSD->new();
+
 		} else {
 	
 			require Slim::Utils::OS::Unix;
