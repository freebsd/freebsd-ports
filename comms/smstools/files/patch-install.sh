--- install.sh.old	2008-02-05 23:45:04.000000000 -0200
+++ install.sh	2008-02-05 23:45:05.000000000 -0200
@@ -2,7 +2,7 @@
 #Do not run directly. This is a helper script for make.
 
 # Remember to edit the config file if you change these default path's.
-BINDIR=/usr/local/bin
+BINDIR=%%PREFIX%%/bin
 SPOOLDIR=/var/spool/sms
 
 
@@ -68,7 +68,7 @@
 copy scripts/unicode2sms $BINDIR/unicode2sms
 
 echo "Installing config file"
-copy examples/smsd.conf.easy /etc/smsd.conf
+copy examples/smsd.conf.easy %%PREFIX%%/etc/smsd.conf
 
 echo "Creating minimum spool directories"
 makedir $SPOOLDIR
@@ -76,15 +76,6 @@
 makedir $SPOOLDIR/outgoing
 makedir $SPOOLDIR/checked
 
-echo "Installing start-script"
-if [ -d /etc/init.d ]; then
-  copy scripts/sms /etc/init.d/sms 
-elif [ -d /sbin/init.d ]; then
-   copy scripts/sms /sbin/init.d/sms
-else
-  echo "  I do not know where to copy scripts/sms. Please find out yourself."
-fi
-
 echo ""
 echo "Example script files are not installed automatically."
-echo 'Please dont forget to edit /etc/smsd.conf.'
+echo 'Please dont forget to edit %%PREFIX%%/etc/smsd.conf.'
