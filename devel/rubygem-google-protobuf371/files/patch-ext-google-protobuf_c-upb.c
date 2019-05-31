--- ext/google/protobuf_c/upb.c.orig	2019-03-28 08:57:36 UTC
+++ ext/google/protobuf_c/upb.c
@@ -14311,7 +14311,7 @@ static bool end_timestamp_zone(upb_json_
   }
 
   /* Normalize tm */
-  seconds = mktime(&p->tm) - timezone;
+  seconds = mktime(&p->tm);
   seconds += 3600 * hours;
 
   /* Check timestamp boundary */
