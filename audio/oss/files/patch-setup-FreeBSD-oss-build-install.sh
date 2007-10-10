--- setup/FreeBSD/oss/build/install.sh.orig	2007-07-18 19:21:12.000000000 -0400
+++ setup/FreeBSD/oss/build/install.sh	2007-10-09 19:51:09.000000000 -0400
@@ -1,11 +1,6 @@
 #!/bin/sh
 
-if test -f /etc/oss.conf
-then
-  . /etc/oss.conf
-else
-  OSSLIBDIR=/usr/lib/oss
-fi
+OSSLIBDIR=${PREFIX}/lib/oss
 
 rm -f osscore_mainline.o
 ln -s osscore.lib osscore_mainline.o
@@ -59,17 +54,4 @@
 	rm -f Makefile
 done
 
-if ! test -f $OSSLIBDIR/etc/installed_drivers
-then
-   echo "-----------------------------"
-   /usr/sbin/ossdetect -v
-   echo "-----------------------------"
-   echo ""
-fi
-
-if test ! -f $OSSLIBDIR/etc/userdefs
-then
-  echo "autosave_mixer yes" > $OSSLIBDIR/etc/userdefs
-fi
-
 exit 0
