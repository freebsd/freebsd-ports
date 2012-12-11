--- dateconv.pl.orig	1998-05-29 12:04:32.000000000 -0700
+++ dateconv.pl	2012-12-11 06:16:24.592709834 -0800
@@ -47,7 +47,8 @@
 }
 
 
-require 'timelocal.pl';
+# require 'timelocal.pl';
+use Time::Local qw(timelocal timegm);
 package dateconv;
 
 # Use timelocal rather than gmtime.
