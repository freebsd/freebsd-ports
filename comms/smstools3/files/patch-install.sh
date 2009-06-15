--- install.sh.orig	2007-04-22 13:43:17.000000000 +0200
+++ install.sh	2008-05-18 00:16:05.000000000 +0200
@@ -3,7 +3,7 @@
 
 BINDIR=$1
 if [ -z "$BINDIR" ]; then
-  BINDIR=/usr/local/bin
+  BINDIR=%%PREFIX%%/bin
 fi
 
 makepath()
@@ -84,14 +84,8 @@
 delete $BINDIR/getsms
 delete $BINDIR/putsms
 
-echo "Installing some scripts"
-copy scripts/sendsms $BINDIR/sendsms
-copy scripts/sms2html $BINDIR/sms2html
-copy scripts/sms2unicode $BINDIR/sms2unicode
-copy scripts/unicode2sms $BINDIR/unicode2sms
-
 echo "Installing config file"
-copy examples/smsd.conf.easy /etc/smsd.conf
+copy examples/smsd.conf.easy %%PREFIX%%/etc/smsd.conf
 
 echo "Creating minimum spool directories"
 makedir /var/spool
@@ -100,22 +94,6 @@
 makedir /var/spool/sms/outgoing
 makedir /var/spool/sms/checked
 
-echo "Installing start-script"
-SMS3SCRIPT=scripts/sms3
-if [ -d /etc/init.d ]; then
-  copy scripts/sms3 /etc/init.d/sms3
-  SMS3SCRIPT=/etc/init.d/sms3
-elif [ -d /sbin/init.d ]; then
-  copy scripts/sms3 /sbin/init.d/sms3
-  SMS3SCRIPT=/sbin/init.d/sms3
-else
-  echo "  I do not know where to copy scripts/sms3. Please find out yourself."
-fi
-
 echo ""
 echo "Example script files are not installed automatically."
-echo 'Please dont forget to edit /etc/smsd.conf.'
-if [ "$BINDIR" != "/usr/local/bin" ]; then
-  echo "You have installed executables to $BINDIR,"
-  echo "you should manually edit $SMS3SCRIPT script."
-fi
+echo 'Please dont forget to edit %%PREFIX%%/etc/smsd.conf.'
