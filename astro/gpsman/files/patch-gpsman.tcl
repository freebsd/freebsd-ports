diff -ruN gpsman.tcl gpsman.tcl
--- gpsman.tcl	Mon Nov 26 03:34:12 2001
+++ gpsman.tcl	Mon Nov 26 16:48:56 2001
@@ -1,6 +1,6 @@
 #!/bin/sh
 # This is a Tcl/Tk script to be interpreted by wish (Tk8.2 or better): \
-exec wish "$0" "$@"
+exec wish8.3 "$0" "$@"
 
 #
 #  gpsman --- GPS Manager: a manager for GPS receiver data
@@ -103,7 +103,7 @@
 	# on Unix systems the path may be passed as an argument
 	set SERIALPORT [lindex $argv 0]
 	# otherwise the default is
-	set DEFSPORT /dev/ttyS0
+	set DEFSPORT /dev/cuaa0
 	# path to directory containing user data
 	set USERDIR ~/.gpsman-dir
 	# name of user preferences file
@@ -121,7 +121,7 @@
 }
 
  # path to directory containing program files
-set SRCDIR gmsrc
+set SRCDIR %%PREFIX%%/share/gpsman/gmsrc
 
 ## the following values can be set from the options dialog of the interface
 
