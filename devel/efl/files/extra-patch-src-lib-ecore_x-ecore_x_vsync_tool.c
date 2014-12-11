# Some users of Nvidia cards reports very high cpu usage by ecore_x_vsync.
# This quick workaround hasn't a visible side effects,
# but better solution is needed.
--- src/lib/ecore_x/_ecore_x_vsync_tool.c	2014-12-03 16:13:51.116115279 +0300
+++ src/lib/ecore_x/ecore_x_vsync_tool.c	2014-12-03 16:14:09.537111198 +0300
@@ -259,6 +259,7 @@
 int
 main(int argc EINA_UNUSED, char **argv EINA_UNUSED)
 {
+   return 0;
    eina_init();
    ecore_app_no_system_modules();
    ecore_init();
