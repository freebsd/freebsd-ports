--- lib/Unix/Uptime.pm.orig	2009-01-19 13:22:27.000000000 -0200
+++ lib/Unix/Uptime.pm	2009-01-19 13:23:38.000000000 -0200
@@ -62,7 +62,8 @@
     my $class = shift;
     
     my $boottime = `sysctl kern.boottime`;
-    my $boot_seconds = $boottime =~ /\s+sec\s+=\s+(\d+),/;
+    $boottime =~ /\s+sec\s+=\s+(\d+),/;
+    my $boot_seconds = $1;
     my $time = time();
     my $uptime = $time - $boot_seconds;
     return $uptime;
