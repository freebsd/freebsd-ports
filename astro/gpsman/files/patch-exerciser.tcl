diff -ruN util/exerciser.tcl util/exerciser.tcl
--- util/exerciser.tcl	Mon Nov 26 03:34:12 2001
+++ util/exerciser.tcl	Mon Nov 26 16:48:56 2001
@@ -1,8 +1,8 @@
 #!/bin/bash
 #\
-exec wish8.2 "$0" ${1+"$@"}
+exec wish8.4 "$0" ${1+"$@"}
 
-set SRLPORT /dev/ttyS0
+set SRLPORT /dev/cuaa0
 set BaudRate 4800
 set Hours "0"
 set Minutes "0"
