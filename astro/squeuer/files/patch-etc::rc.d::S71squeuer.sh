$FreeBSD$

--- etc/rc.d/S71squeuer.sh.orig	Thu Oct 31 20:38:18 2002
+++ etc/rc.d/S71squeuer.sh	Thu Aug  7 12:25:20 2003
@@ -3,14 +3,16 @@
 # Squeuer
 #
 
-squeuer=/usr/local/bin/squeuer.pl
-pid_file=/var/run/squeuer.pid
+squeuer=%%PREFIX%%/sbin/squeuer
+squeuer_conf=%%PREFIX%%/etc/squeuer.conf
+pid_file=%%PIDDIR%%/squeuer.pid
+squeuer_user=squeuer
 
 SYSV3=1; export SYSV3
 
 case $1 in
 	start)	echo -n ' squeuer'
-		su squeuer -c $squeuer > $pid_file &
+		su $squeuer_user -c "$squeuer -f $squeuer_conf" > $pid_file &
 		;;
 
 	stop)	if [ -f $pid_file ]; then
