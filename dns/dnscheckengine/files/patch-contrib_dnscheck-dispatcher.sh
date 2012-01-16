--- contrib/dnscheck-dispatcher.sh.orig	2010-06-29 02:15:59.000000000 -0700
+++ contrib/dnscheck-dispatcher.sh	2012-01-15 15:32:16.000000000 -0800
@@ -6,45 +6,18 @@
 
 # Add the following lines to /etc/rc.conf to enable the dnscheck-dispatcher daemon:
 #
-#dnscheck_dispatcher_enable="YES"
-
-#
-# DO NOT CHANGE THESE DEFAULT VALUES HERE
-# SET THEM IN THE /etc/rc.conf FILE
-#
-utility_enable=${dnscheck_dispatcher_enable-"NO"}
-utility_flags=${dnscheck_dispatcher_flags-""}
-utility_pidfile=${dnscheck_dispatcher_pidfile-"/var/run/dnscheck_dispatcher.pid"}
+# dnscheck_dispatcher_enable="YES"
 
 . /etc/rc.subr
 
 name="dnscheck_dispatcher"
-rcvar=`set_rcvar`
-command="/usr/local/bin/dnscheck-dispatcher"
+rcvar=dnscheck_dispatcher_enable
 
-pidfile="${utility_pidfile}"
+load_rc_config $name
 
-start_cmd=dnscheck_dispatcher_start
-stop_cmd=dnscheck_dispatcher_stop
-status_cmd=dnscheck_dispatcher_status
-
-dnscheck_dispatcher_start() {
-   /bin/echo "Starting ${name}." && \
-   /usr/bin/nice -5 ${command} ${utility_flags} ${command_args}
-}
-
-
-dnscheck_dispatcher_stop() {
-   /bin/echo "Stopping ${name}." && \
-   /bin/kill -9 `cat ${utility_pidfile}` && /bin/rm ${utility_pidfile}
-}
-
-dnscheck_dispatcher_status() {
-   if [ -e $utility_pidfile ]
-       then echo "dnscheck_dispatcher is running as pid `cat ${utility_pidfile}`."
-       else echo "dnscheck_dispatcher is not running."
-   fi
-}
+dnscheck_dispatcher_enable=${dnscheck_dispatcher_enable-"NO"}
+pidfile=${dnscheck_dispatcher_pidfile-"/var/run/dnscheck_dispatcher.pid"}
+
+command="%%PREFIX%%/bin/dnscheck-dispatcher"
 
-load_rc_config $name
 run_rc_command "$1"
