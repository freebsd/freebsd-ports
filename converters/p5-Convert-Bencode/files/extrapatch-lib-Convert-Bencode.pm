--- lib/Convert/Bencode.pm.orig	Tue Oct  7 05:07:53 2003
+++ lib/Convert/Bencode.pm	Mon Feb 20 01:00:56 2006
@@ -64,12 +64,10 @@
 =cut
 
 use strict;
-use warnings;
-use bytes;
 
 BEGIN {
 	use Exporter ();
-	our ($VERSION, @ISA, @EXPORT, @EXPORT_OK, @EXPORT_FAIL, %EXPORT_TAGS);
+	use vars qw($VERSION @ISA @EXPORT @EXPORT_OK @EXPORT_FAIL %EXPORT_TAGS);
 
 	$VERSION 	= 1.03;
 	@ISA		= qw(Exporter);
@@ -77,7 +75,7 @@
 	@EXPORT_FAIL	= qw(&_dechunk);
 	%EXPORT_TAGS	= (all => [qw(&bencode &bdecode)]);
 }
-our @EXPORT_OK;
+use vars @EXPORT_OK;
 
 END { }
 
