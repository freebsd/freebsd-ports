--- ags/lib/ags_uuid.c.orig	2019-02-11 23:41:39 UTC
+++ ags/lib/ags_uuid.c
@@ -117,7 +117,7 @@ ags_uuid_generate(AgsUUID *ptr)
     return;
   }
 
-  uuid_generate_time_safe(ptr[0]);
+  uuid_generate_time(ptr[0]); // uuid_generate_time_safe() is missing in FreeBSD's libuuid.so
 }
 
 /**
