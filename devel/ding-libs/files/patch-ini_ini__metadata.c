--- ini/ini_metadata.c.orig	2026-02-10 07:24:13 UTC
+++ ini/ini_metadata.c
@@ -172,8 +172,8 @@ int collect_metadata(uint32_t metaflags,
         }
 
         /* Modification time stamp */
-        snprintf(buff, CONVERSION_BUFFER, "%ld",
-                 (long int)file_stats.st_mtime);
+        snprintf(buff, CONVERSION_BUFFER, "%lld",
+                 (long long)file_stats.st_mtime);
         error = col_add_str_property(metasec,
                                      NULL,
                                      INI_META_KEY_MODIFIED,
@@ -197,23 +197,11 @@ int collect_metadata(uint32_t metaflags,
             return error;
         }
 
-        /* The device ID can actualy be bigger than
-         * 32-bits according to the type sizes.
-         * However it is probaly not going to happen
-         * on a real system.
-         * Add a check for this case.
-         */
-        if (file_stats.st_dev > ULONG_MAX) {
-            TRACE_ERROR_NUMBER("Device is out of range", ERANGE);
-            col_destroy_collection(metasec);
-            return ERANGE;
-        }
-
         /* Device  ID */
         TRACE_INFO_LNUMBER("Device ID", file_stats.st_dev);
 
-        snprintf(buff, CONVERSION_BUFFER, "%lu",
-                 (unsigned long)file_stats.st_dev);
+        snprintf(buff, CONVERSION_BUFFER, "%llu",
+                 (unsigned long long)file_stats.st_dev);
         error = col_add_str_property(metasec,
                                      NULL,
                                      INI_META_KEY_DEV,
@@ -226,8 +214,8 @@ int collect_metadata(uint32_t metaflags,
         }
 
         /* i-node */
-        snprintf(buff, CONVERSION_BUFFER, "%lu",
-                (unsigned long)file_stats.st_ino);
+        snprintf(buff, CONVERSION_BUFFER, "%llu",
+                (unsigned long long)file_stats.st_ino);
         error = col_add_str_property(metasec,
                                      NULL,
                                      INI_META_KEY_INODE,
@@ -414,14 +402,14 @@ int config_access_check(struct collection_item *metada
 
 }
 
-static unsigned long get_checked_value(struct collection_item *metadata,
+static unsigned long long get_checked_value(struct collection_item *metadata,
                                        const char *key,
                                        int *err)
 {
 
     int error = EOK;
     struct collection_item *item = NULL;
-    unsigned long value;
+    unsigned long long value;
 
     TRACE_FLOW_STRING("get_checked_value", "Entry");
     TRACE_INFO_STRING("Key", key);
@@ -445,8 +433,8 @@ static unsigned long get_checked_value(struct collecti
         return 0;
     }
 
-    value = get_ulong_config_value(item, 1, -1, &error);
-    if ((error) || (value == -1)) {
+    value = (unsigned long long)get_uint64_config_value(item, 1, 0, &error);
+    if (error) {
         TRACE_ERROR_NUMBER("Conversion failed", EINVAL);
         *err = EINVAL;
         return 0;
@@ -467,7 +455,7 @@ int config_changed(struct collection_item *metadata,
 {
     int error = EOK;
     struct collection_item *md[2];
-    unsigned long value[3][2];
+    unsigned long long value[3][2];
     const char *key[] = { INI_META_KEY_MODIFIED,
                           INI_META_KEY_DEV,
                           INI_META_KEY_INODE };
