--- cddb.pl.orig	2005-10-06 06:00:59 UTC
+++ cddb.pl
@@ -85,7 +85,7 @@ $CDDB_get::debug=1 if($option{D});
 # following variables just need to be declared if different from defaults
 # defaults are listed below (cdrom default is os specific)
 
-# $config{CDDB_HOST}="freedb.freedb.org";	# set cddb host
+# $config{CDDB_HOST}="gnudb.gnudb.org";		# set cddb host
 if($option{H}) {
   $config{CDDB_HOST}=$option{H};
 }
