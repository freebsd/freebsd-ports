--- cJSON.c.orig	2020-04-02 15:35:50 UTC
+++ cJSON.c
@@ -106,7 +106,7 @@ CJSON_PUBLIC(double) cJSON_GetNumberValue(cJSON *item)
 {
     if (!cJSON_IsNumber(item)) 
     {
-        return NAN;
+        return (double)NAN;
     }
 
     return item->valuedouble;
