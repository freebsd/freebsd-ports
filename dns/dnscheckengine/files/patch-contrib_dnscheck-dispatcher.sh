
$FreeBSD$

--- contrib/dnscheck-dispatcher.sh.orig
+++ contrib/dnscheck-dispatcher.sh
@@ -20,7 +20,7 @@
 
 name="dnscheck_dispatcher"
 rcvar=`set_rcvar`
-command="/usr/local/bin/dnscheck-dispatcher"
+command="%%PREFIX%%/libexec/dnscheck/dnscheck-dispatcher"
 
 pidfile="${utility_pidfile}"
 
