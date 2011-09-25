--- gio/gdesktopappinfo.c.orig	2011-09-25 11:41:14.000000000 -0400
+++ gio/gdesktopappinfo.c	2011-09-25 11:41:18.000000000 -0400
@@ -1515,18 +1515,29 @@ update_mimeapps_list (const char  *deskt
            */
           if (!explicit_default)
             {
-              system_list = get_all_desktop_entries_for_mime_type (content_type, (const char **) list, FALSE, NULL);
+              char *user_default;
+              /* The system default can be in the list, don't exclude it */
+              system_list = get_all_desktop_entries_for_mime_type (content_type, NULL, FALSE, &user_default);
 
-              if (system_list != NULL)
+              string = NULL;
+              if (user_default != NULL)
+                {
+                  /* There is an existing default set in a lower priority defaults file, re-use it */
+                  string = user_default;
+                }
+              else if (system_list != NULL)
                 {
                   string = system_list->data;
-
+                }
+              if (string)
+                {
                   g_key_file_set_string (key_file,
                                          DEFAULT_APPLICATIONS_GROUP,
                                          content_types[k],
                                          string);
                 }
 
+              g_free (user_default);
               g_list_free_full (system_list, g_free);
             }
         }
