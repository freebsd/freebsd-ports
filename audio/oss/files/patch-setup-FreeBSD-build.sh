--- setup/FreeBSD/build.sh.orig	2007-10-25 17:48:59.000000000 -0400
+++ setup/FreeBSD/build.sh	2007-10-25 17:59:18.000000000 -0400
@@ -23,7 +23,7 @@
 mkdir -p prototype/usr/man/man1
 mkdir -p prototype/usr/man/man8
 
-echo "OSSLIBDIR=/usr/lib/oss" > prototype/etc/oss.conf
+echo "OSSLIBDIR=%%PREFIX%%/lib/oss" > prototype/etc/oss.conf
 
 cp -r $SRCDIR/setup/FreeBSD/oss prototype/usr/lib/
 cp $SRCDIR/kernel/OS/FreeBSD/wrapper/bsddefs.h prototype/usr/lib/oss/build/
