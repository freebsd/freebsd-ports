--- doc/conf-o2n.rb.orig	Thu Nov  4 02:08:37 2004
+++ doc/conf-o2n.rb	Thu Nov  4 08:18:09 2004
@@ -41,7 +41,7 @@
 
     def global
       ["HOST", "PORT", "MAX_CLIENTS", "DAEMON", "TCPWRAP",
-       "PIDFILE", "LOG_FILE"].each do |var|
+       "PID_FILE", "LOG_FILE"].each do |var|
         set_if_def(SKKServerConfig, var, var.downcase)
       end
 
