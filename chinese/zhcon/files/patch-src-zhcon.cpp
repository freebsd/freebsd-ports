--- src/zhcon.cpp.orig	Tue Nov 26 01:35:04 2002
+++ src/zhcon.cpp	Tue Nov 26 01:35:25 2002
@@ -131,7 +131,7 @@
     string cfgfile = getenv("HOME");
     cfgfile += "/.zhconrc";
     if (access(cfgfile.c_str(), R_OK) != 0)
-        cfgfile = "/etc/zhcon.conf";
+        cfgfile = PREFIX"/etc/zhcon.conf";
 
     //for debug,a pause enable us to attach zhcon's pid in gdb
     //char c;cin>>c;
