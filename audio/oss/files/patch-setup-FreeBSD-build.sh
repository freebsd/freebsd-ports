--- setup/FreeBSD/build.sh.orig	Fri Jun 22 15:55:18 2007
+++ setup/FreeBSD/build.sh	Fri Jun 22 15:56:34 2007
@@ -23,7 +23,7 @@
 mkdir prototype/usr/man/man1
 mkdir prototype/usr/man/man8
 
-echo "OSSLIBDIR=/usr/lib/oss" > prototype/etc/oss.conf
+echo "OSSLIBDIR=%%PREFIX%%/lib/oss" > prototype/etc/oss.conf
 
 cp -r $SRCDIR/setup/FreeBSD/oss prototype/usr/lib/
 cp $SRCDIR/kernel/OS/FreeBSD/wrapper/bsddefs.h prototype/usr/lib/oss/build/
