--- gconf/gconf-client.c.orig	2009-05-10 15:54:11.000000000 -0400
+++ gconf/gconf-client.c	2009-05-10 15:55:22.000000000 -0400
@@ -1199,10 +1199,11 @@ gconf_client_key_is_writable (GConfClien
 
   if (gconf_client_lookup (client, key, &entry))
     {
-      g_assert (entry != NULL);
-
-      trace ("CACHED: Checking whether key '%s' is writable", key);
-      return gconf_entry_get_is_writable (entry);
+      if (entry != NULL)
+        {
+          trace ("CACHED: Checking whether key '%s' is writable", key);
+          return gconf_entry_get_is_writable (entry);
+        }
     }
   
   trace ("REMOTE: Checking whether key '%s' is writable", key);
@@ -1406,9 +1407,7 @@ gconf_client_get_default_from_schema (GC
    */
   if (gconf_client_lookup (client, key, &entry))
     {
-      g_assert (entry != NULL);
-
-      if (gconf_entry_get_is_default (entry))
+      if (entry != NULL && gconf_entry_get_is_default (entry))
         {
 	  trace ("CACHED: Getting schema default for '%s'", key);
 
