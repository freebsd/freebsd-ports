--- TemporaryBag.pm.orig	Sun Nov 10 17:33:03 2002
+++ TemporaryBag.pm	Fri May 23 13:00:03 2003
@@ -2,7 +2,10 @@
 
 use strict;
 
-use Fcntl qw/:DEFAULT :seek/;
+use Fcntl qw/:DEFAULT/;
+use constant SEEK_SET	=> 0;
+use constant SEEK_END	=> 2;
+use Symbol;
 use Carp;
 use File::Temp ':mktemp';
 
@@ -14,7 +17,7 @@
 use constant RECENTNESS  => 4;
 use constant FINGERPRINT => 4;
 
-our ($VERSION, $Threshold, $TempPath, $MaxOpen);
+use vars qw($VERSION $Threshold $TempPath $MaxOpen);
 
 $VERSION = '0.06';
 
@@ -243,6 +246,7 @@
     }
     if (defined ($fn = $self->[FILENAME])) {
 	croak "TemporaryBag object seems to be collapsed " if (!-e $fn) or (!-f _);
+	$fh=gensym;
 	sysopen($fh, $fn, O_RDWR) or croak "TemporaryBag object seems to be collapsed OP";
 	croak "TemporaryBag object seems to be collapsed " if (-l $fn);
 	binmode $fh;
