--- plugin/icedteanp/IcedTeaNPPlugin.cc.orig	2019-08-02 14:08:17.000000000 +0200
+++ plugin/icedteanp/IcedTeaNPPlugin.cc	2020-03-22 00:41:29.958009000 +0100
@@ -1627,9 +1627,9 @@
     command_line.push_back("-classpath");
     command_line.push_back(get_plugin_jfx_jar());
     command_line.push_back("--patch-module");
-    command_line.push_back("java.desktop="PLUGIN_JAR":"NETX_JAR);
+    command_line.push_back("java.desktop=" PLUGIN_JAR":" NETX_JAR);
     command_line.push_back("--patch-module");
-    command_line.push_back("jdk.jsobject="JSOBJECT_JAR);
+    command_line.push_back("jdk.jsobject=" JSOBJECT_JAR);
     command_line.push_back("--add-reads");
     command_line.push_back("java.base=ALL-UNNAMED,java.desktop");
     command_line.push_back("--add-reads");
