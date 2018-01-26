--- remhost.cc.orig	2018-01-26 22:32:32.721538000 +0000
+++ remhost.cc	2018-01-26 22:38:33.566682000 +0000
@@ -62,7 +62,7 @@
     std::ostringstream serverName;
     serverName << "@" << SERVER_MACH_NAME;
     int serverPortNum = SERVER_PORT_NUM;
-    char *distingProp = '\0';
+    const char *distingProp = "";
 
     int nextarg = 1;
     for (; nextarg < argc; nextarg++) {
