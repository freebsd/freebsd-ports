--- gpsman.tcl.orig	2013-10-06 21:12:47 UTC
+++ gpsman.tcl
@@ -1,6 +1,6 @@
 #!/bin/sh
 # This is a Tcl/Tk script to be interpreted by wish (Tk8.3 or better): \
-exec wish "$0" -- "$@"
+exec %%WISH%% "$0" -- "$@"
 
 # This is the main file of:
 #
@@ -247,7 +247,7 @@ switch $tcl_platform(platform) {
 }
 
  # path to directory containing program files
-set SRCDIR gmsrc
+set SRCDIR %%GPSMANDIR%%/gmsrc
 
 # all other default configuration is now done in file $SRCDIR/config.tcl
 
