--- FreeBSD/tbd.sh.orig	Wed Jun 23 16:02:28 2004
+++ FreeBSD/tbd.sh	Wed Jun 23 16:02:59 2004
@@ -2,7 +2,7 @@
 # $Id: tbd.sh,v 1.1.1.1 2002/08/10 20:33:40 wb6ymh Exp $

 pidfiledir=/var/run
-tbd=/usr/local/libexec/tbd
+tbd=%%PREFIX%%/libexec/tbd

 # start
 if [ "x$1" = "x" -o "x$1" = "xstart" ]; then
