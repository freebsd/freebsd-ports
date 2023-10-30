--- plugins/synthpod_common_d2tk.c.orig	2023-10-30 01:59:20 UTC
+++ plugins/synthpod_common_d2tk.c
@@ -305,7 +305,7 @@ _plug_populate(plughandle_t *handle, const char *patte
 
 			const char *name = lilv_node_as_string(name_node);
 
-			if(fnmatch(pattern, name, FNM_CASEFOLD | FNM_EXTMATCH) == 0)
+			if(fnmatch(pattern, name, FNM_CASEFOLD /*| FNM_EXTMATCH*/) == 0)
 			{
 				entry_t *entry = &handle->lplugs[handle->nplugs++];
 				entry->data = plug;
