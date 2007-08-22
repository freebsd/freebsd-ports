--- install.sh.orig	Sat Jul 29 14:50:42 2006
+++ install.sh	Fri Jul 20 09:49:08 2007
@@ -47,24 +47,35 @@
 fi
 
 echo "Installing binary program files"
-makedir /usr/local
-makedir /usr/local/bin
 if [ -f src/smsd.exe ]; then
-  forcecopy src/smsd.exe /usr/local/bin/smsd.exe
+  forcecopy src/smsd.exe %%PREFIX%%/bin/smsd.exe
 else
-  forcecopy src/smsd /usr/local/bin/smsd
+  forcecopy src/smsd %%PREFIX%%/bin/smsd
 fi
-delete /usr/local/bin/getsms
-delete /usr/local/bin/putsms
 
 echo "Installing some scripts"
-copy scripts/sendsms /usr/local/bin/sendsms
-copy scripts/sms2html /usr/local/bin/sms2html
-copy scripts/sms2unicode /usr/local/bin/sms2unicode
-copy scripts/unicode2sms /usr/local/bin/unicode2sms
+copy scripts/sendsms %%PREFIX%%/bin/sendsms
+copy scripts/sms2html %%PREFIX%%/bin/sms2html
+copy scripts/sms2unicode %%PREFIX%%/bin/sms2unicode
+copy scripts/unicode2sms %%PREFIX%%/bin/unicode2sms
 
 echo "Installing config file"
-copy examples/smsd.conf.easy /etc/smsd.conf
+copy examples/smsd.conf.full %%PREFIX%%/etc/smsd.conf.sample
+
+echo "Installing additional examples"
+makedir %%EXAMPLESDIR%%
+copy examples/operator_logo1.sms %%EXAMPLESDIR%%/operator_logo1.sms
+copy examples/operator_logo2.sms %%EXAMPLESDIR%%/operator_logo2.sms
+copy examples/received_report.sms %%EXAMPLESDIR%%/received_report.sms
+copy examples/received_sms.sms %%EXAMPLESDIR%%/received_sms.sms
+copy examples/send_sms.sms %%EXAMPLESDIR%%/send_sms.sms
+copy examples/send_sms_unicode.sms %%EXAMPLESDIR%%/send_sms_unicode.sms
+copy examples/smsd.conf.easy %%EXAMPLESDIR%%/smsd.conf.easy
+copy examples/smsd.conf.full %%EXAMPLESDIR%%/smsd.conf.full
+copy scripts/email2sms %%EXAMPLESDIR%%/email2sms
+copy scripts/smsevent %%EXAMPLESDIR%%/smsevent
+copy scripts/sql_demo %%EXAMPLESDIR%%/sql_demo
+copy scripts/mysmsd %%EXAMPLESDIR%%/mysmsd
 
 echo "Creating minimum spool directories"
 makedir /var/spool
@@ -73,15 +84,5 @@
 makedir /var/spool/sms/outgoing
 makedir /var/spool/sms/checked
 
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
-echo "Example script files are not installed automatically."
-echo 'Please dont forget to edit /etc/smsd.conf.'
+echo 'Please dont forget to create/edit %%PREFIX%%/etc/smsd.conf.'
