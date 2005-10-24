
$FreeBSD$

--- lib/snmp/src/misc/snmp_config.erl.orig
+++ lib/snmp/src/misc/snmp_config.erl
@@ -1722,7 +1722,7 @@
 "%% {\"standard inform\", \"std_inform\", inform}.\n"
 "%%\n\n",
     Hdr = header() ++ Comment, 
-    Conf = [{"stadard_trap", "std_trap", NotifyType}],
+    Conf = [{"standard trap", "std_trap", NotifyType}],
     write_agent_notify_config(Dir, Hdr, Conf).
 
 write_agent_notify_config(Dir, Hdr, Conf) 
