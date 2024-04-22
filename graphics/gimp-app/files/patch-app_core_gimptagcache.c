--- app/core/gimptagcache.c.orig	2023-11-05 23:49:04 UTC
+++ app/core/gimptagcache.c
@@ -397,8 +397,8 @@ gimp_tag_cache_save (GimpTagCache *cache)
 
       identifier_string = g_markup_escape_text (g_quark_to_string (cache_rec->identifier), -1);
       g_string_append_printf (buf, "\n  <resource identifier=\"%s\" checksum=\"%s\">\n",
-                              identifier_string,
-                              g_quark_to_string (cache_rec->checksum));
+                              identifier_string ? identifier_string : "(NULL)",
+                              cache_rec->checksum ? g_quark_to_string (cache_rec->checksum) : "(NULL)");
       g_free (identifier_string);
 
       for (tag_iterator = cache_rec->tags;
@@ -607,7 +607,7 @@ gimp_tag_cache_load_text (GMarkupParseContext  *contex
       else
         {
           g_warning ("dropping invalid tag '%s' from '%s'\n", buffer,
-                     g_quark_to_string (parse_data->current_record.identifier));
+                     parse_data->current_record.identifier ? g_quark_to_string (parse_data->current_record.identifier) : "(NULL)");
         }
     }
 }
