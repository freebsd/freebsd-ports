--- lib/Config/Auto.pm.orig	Sat Feb 21 12:39:16 2004
+++ lib/Config/Auto.pm	Sat Feb 21 12:40:02 2004
@@ -120,8 +120,8 @@
 
     # Some general sanity checks
     if (exists $score{perl}) {
-        $score{perl} /= 2   unless ("@$data_r" =~ tr/;//) > 3 or $#$data_r < 3;
-        delete $score{perl} unless ("@$data_r" =~ tr/;//);
+        $score{perl} /= 2   unless ("@$data_r" =~ /;/) > 3 or $#$data_r < 3;
+        delete $score{perl} unless ("@$data_r" =~ /;/);
         delete $score{perl} unless ("@$data_r" =~ /([\$\@\%]\w+)/);
     }
 
