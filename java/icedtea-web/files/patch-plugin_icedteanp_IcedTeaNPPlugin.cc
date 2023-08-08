--- plugin/icedteanp/IcedTeaNPPlugin.cc.orig	2021-05-17 09:24:37 UTC
+++ plugin/icedteanp/IcedTeaNPPlugin.cc
@@ -1627,9 +1627,9 @@ plugin_start_appletviewer (ITNPPluginData* data)
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
