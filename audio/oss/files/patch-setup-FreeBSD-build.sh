--- setup/FreeBSD/build.sh.orig	2007-10-25 17:48:59.000000000 -0400
+++ setup/FreeBSD/build.sh	2007-10-25 17:59:18.000000000 -0400
@@ -23,11 +23,11 @@
 mkdir -p prototype/usr/man/man1
 mkdir -p prototype/usr/man/man8
 
-echo "OSSLIBDIR=/usr/lib/oss" > prototype/etc/oss.conf
+echo "OSSLIBDIR=%%PREFIX%%/lib/oss" > prototype/etc/oss.conf
 
 cp -r $SRCDIR/setup/FreeBSD/oss prototype/usr/lib/
 cp $SRCDIR/kernel/OS/FreeBSD/wrapper/bsddefs.h prototype/usr/lib/oss/build/
-cp $SRCDIR/include/ossddk/oss_exports.h prototype/usr/lib/oss/build/
+cp $SRCDIR/kernel/framework/include/ossddk/oss_exports.h prototype/usr/lib/oss/build/
 
 cp $SRCDIR/include/soundcard.h prototype/usr/lib/oss/include/sys/
 #cp $SRCDIR/lib/libOSSlib/midiparser.h prototype/usr/lib/oss/include/
