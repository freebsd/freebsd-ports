--- Makefile.PL
+++ Makefile.PL
@@ -95,16 +95,17 @@
 
 # checking for various functions
 
-my %funcs = (ttyname   => "",
-	     openpty   => "-lutil",
-	     _getpty   => "",
-	     strlcpy   => "",
-	     sigaction => "",
-	     grantpt   => "",
-	     unlockpt  => "",
-	     getpt     => "",
-	     ptsname   => "",
-	     ptsname_r => "",
+my %funcs = (ttyname      => "",
+	     openpty      => "-lutil",
+	     _getpty      => "",
+	     strlcpy      => "",
+	     sigaction    => "",
+	     grantpt      => "",
+	     unlockpt     => "",
+	     getpt        => "",
+	     posix_openpt => "",
+	     ptsname      => "",
+	     ptsname_r    => "",
 	    );
 
 foreach my $f (sort keys %funcs) {
@@ -290,7 +291,7 @@
     msg => "WARNING!  Neither ptsname() nor ptsname_r() could be found,\n so we cannot use a high-level interface like openpty().\n",
    },
    {
-    defines => [qw"-DHAVE_DEV_PTMX -DHAVE_DEV_PTYM_CLONE -DHAVE_DEV_PTC -DHAVE_DEV_PTMX_BSD -DHAVE__GETPTY -DHAVE_OPENPTY -DHAVE_GETPT"],
+    defines => [qw"-DHAVE_DEV_PTMX -DHAVE_DEV_PTYM_CLONE -DHAVE_DEV_PTC -DHAVE_DEV_PTMX_BSD -DHAVE__GETPTY -DHAVE_OPENPTY -DHAVE_GETPT -DHAVE_POSIX_OPENPT"],
     msg => "No high-level lib or clone device has been found, we will use BSD-style ptys.\n",
    },
   ) {
