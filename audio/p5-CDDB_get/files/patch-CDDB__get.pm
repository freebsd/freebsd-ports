--- CDDB_get.pm.orig	2012-03-06 18:28:24 UTC
+++ CDDB_get.pm
@@ -66,7 +66,7 @@ my $CDROM_MSF=0x02;
 
 # default config
 
-my $CDDB_HOST = "freedb.freedb.org";
+my $CDDB_HOST = "gnudb.gnudb.org";
 my $CDDB_PORT = 8880;
 my $CDDB_MODE = "cddb";
 my $CD_DEVICE = "/dev/cdrom";
@@ -608,7 +608,7 @@ CDDB - Read the CDDB entry for an audio CD in your dri
 
  # following variables just need to be declared if different from defaults
 
- $config{CDDB_HOST}="freedb.freedb.org";	# set cddb host
+ $config{CDDB_HOST}="gnudb.gnudb.org";		# set cddb host
  $config{CDDB_PORT}=8880;			# set cddb port
  $config{CDDB_MODE}="cddb";			# set cddb mode: cddb or http
  $config{CD_DEVICE}="/dev/cdrom";		# set cd device
