--- ags/lib/ags_uuid.c.orig	2020-01-14 00:52:03 UTC
+++ ags/lib/ags_uuid.c
@@ -119,7 +119,7 @@ ags_uuid_generate(AgsUUID *ptr)
     return;
   }
 
-  uuid_generate_time_safe(ptr->data);
+  uuid_generate_time(ptr->data); // uuid_generate_time_safe() is missing in FreeBSD's libuuid.so
 }
 
 /**
