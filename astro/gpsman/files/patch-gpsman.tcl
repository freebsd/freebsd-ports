diff -ruN gpsman.tcl gpsman.tcl
--- gpsman.tcl	Fri Mar  7 07:16:40 2003
+++ gpsman.tcl	Mon Mar 10 17:28:28 2003
@@ -1,6 +1,6 @@
 #!/bin/sh
 # This is a Tcl/Tk script to be interpreted by wish (Tk8.4 or better): \
-exec wish "$0" -- "$@"
+exec wish8.4 "$0" -- "$@"
 
 #
 #  gpsman --- GPS Manager: a manager for GPS receiver data
@@ -159,7 +159,7 @@
 	    set CMDLINE 1
 	}
 	# otherwise the default is
-	set DEFSPORT /dev/ttyS0
+	set DEFSPORT /dev/cuaa0
 	# path to directory containing user data
 	set USERDIR ~/.gpsman-dir
 	# name of user preferences file
@@ -182,7 +182,7 @@
 }
 
  # path to directory containing program files
-set SRCDIR gmsrc
+set SRCDIR %%PREFIX%%/share/gpsman/gmsrc
 
 ## the following values can be set from the options dialog of the interface
 
