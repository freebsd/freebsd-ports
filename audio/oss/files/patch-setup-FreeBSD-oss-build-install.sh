--- setup/FreeBSD/oss/build/install.sh.orig	Thu Jan 11 23:48:14 2007
+++ setup/FreeBSD/oss/build/install.sh	Fri Jun 22 15:15:32 2007
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
@@ -58,13 +53,5 @@
 	make clean > /dev/null 2>&1
 	rm -f Makefile
 done
-
-if ! test -f $OSSLIBDIR/etc/installed_drivers
-then
-   echo "-----------------------------"
-   /usr/sbin/ossdetect -v
-   echo "-----------------------------"
-   echo ""
-fi
 
 exit 0
