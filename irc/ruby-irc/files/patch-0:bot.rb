--- bot.rb.orig	Wed Jun 14 05:12:45 2000
+++ bot.rb	Fri Jan 19 17:17:42 2001
@@ -30,7 +30,7 @@
 parseArgs(0, "server", "",
 	  "server:", "logfile:", "nick:", "operator:", "username:")
 Server = $OPT_server
-Operator = $OPT_operator || "Igapon"
+Operator = $OPT_operator || "igapon!igarashi@mahon.ueda.info.waseda.ac.jp"
 Nick = $OPT_nick || "Bot"
 UserName = $OPT_username || "iga"
 AgentName = $OPT_agentname || "Ruby¤Á¤ã¤ó"
