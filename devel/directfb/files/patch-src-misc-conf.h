--- src/misc/conf.c
+++ src/misc/conf.c
@@ -56,6 +56,8 @@
 
 D_DEBUG_DOMAIN( DirectFB_Config, "DirectFB/Config", "Runtime configuration options for DirectFB" );
 
+typedef unsigned long ulong;
+
 DFBConfig *dfb_config = NULL;
 
 static const char *config_usage =
