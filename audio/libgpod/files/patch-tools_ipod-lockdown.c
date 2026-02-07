Deprecated method plist_dict_insert_item() has been removed and
replaced by plist_dict_set_item() in devel/libplist >= 2.3.0.

--- tools/ipod-lockdown.c.orig	2013-07-10 13:57:39 UTC
+++ tools/ipod-lockdown.c
@@ -100,7 +100,7 @@ read_sysinfo_extended_by_uuid (const char *uuid)
 	plist_get_string_val(ptr, &str);
 	if (str != NULL) {
 	    ptr = plist_new_string(str);
-	    plist_dict_insert_item(value, "SerialNumber", ptr);
+	    plist_dict_set_item(value, "SerialNumber", ptr);
 	    free(str);
 	}
 
@@ -112,15 +112,15 @@ read_sysinfo_extended_by_uuid (const char *uuid)
 	plist_get_string_val(ptr, &str);
 	if (str != NULL) {
 	    ptr = plist_new_string(str);
-	    plist_dict_insert_item(value, "VisibleBuildID", ptr);
+	    plist_dict_set_item(value, "VisibleBuildID", ptr);
 	    free(str);
 	}
 
 	ptr = plist_new_string(uuid);
-	plist_dict_insert_item(value, "FireWireGUID", ptr);
+	plist_dict_set_item(value, "FireWireGUID", ptr);
 
 	ptr = plist_new_string(uuid);
-	plist_dict_insert_item(value, "UniqueDeviceID", ptr);
+	plist_dict_set_item(value, "UniqueDeviceID", ptr);
 
 	plist_to_xml(value, &xml, &xml_length);
 
