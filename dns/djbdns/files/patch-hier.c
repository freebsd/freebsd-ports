--- hier.c.orig	Wed Apr 14 09:38:45 2004
+++ hier.c	Wed Apr 14 09:39:16 2004
@@ -2,10 +2,10 @@
 
 void hier()
 {
-  c("/","etc","dnsroots.global",-1,-1,0644);
+  c(auto_home,"etc","dnsroots.global",-1,-1,0644);
 
-  h(auto_home,-1,-1,02755);
-  d(auto_home,"bin",-1,-1,02755);
+  h(auto_home,-1,-1,0755);
+  d(auto_home,"bin",-1,-1,0755);
 
   c(auto_home,"bin","dnscache-conf",-1,-1,0755);
   c(auto_home,"bin","tinydns-conf",-1,-1,0755);
