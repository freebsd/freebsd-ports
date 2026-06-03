--- libfoundry/platform/foundry-os-info.c.orig	2025-10-28 23:23:12 UTC
+++ libfoundry/platform/foundry-os-info.c
@@ -60,7 +60,7 @@ foundry_get_os_info (const char *key_name)
   if (g_once_init_enter (&initialized))
     {
       if (g_file_test ("/.flatpak-info", G_FILE_TEST_EXISTS))
-        g_file_get_contents ("/var/run/host/os-release", &os_release_data, &os_release_len, NULL);
+        g_file_get_contents ("/var/run/os-release", &os_release_data, &os_release_len, NULL);
       g_once_init_leave (&initialized, TRUE);
     }
 
