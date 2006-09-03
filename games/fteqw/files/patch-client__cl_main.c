--- ./client/cl_main.c.orig	Tue Jul 18 00:34:50 2006
+++ ./client/cl_main.c	Sat Sep  2 19:03:55 2006
@@ -2873,11 +2873,13 @@
 
 	if (host_initialized && cfg_save_name.string && *cfg_save_name.string)
 	{
-		if (strchr(cfg_save_name.string, '.'))
+#if 0
+		if (strstr(cfg_save_name.string, ".."))
 		{
 			Con_TPrintf (TLC_CONFIGCFG_WRITEFAILED);
 			return;
 		}
+#endif
 
 		f = FS_OpenVFS(va("%s.cfg",cfg_save_name.string), "wb", FS_GAMEONLY);
 		if (!f)
