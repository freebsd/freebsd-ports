--- Makefile.PL.orig	Wed Jan 17 05:49:27 2007
+++ Makefile.PL	Sun Feb 11 21:17:10 2007
@@ -17,8 +17,8 @@
 	chomp($libver);
 	Carp::croak("Please install taglib ver 1.4.*") unless 
 		$libver =~ m/^1\.4/io;
-	our $libs = qx(taglib-config --libs);
-	our $inc  = ' -I/usr/include -I./include -I. '. qx(taglib-config --cflags);
+	our $libs = qx(taglib-config --libs); chomp($libs); $libs.=' -liconv';
+	our $inc  = ' -I/usr/include -I./include -I. -I$(PREFIX)/include '. qx(taglib-config --cflags);
 }
 
 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
