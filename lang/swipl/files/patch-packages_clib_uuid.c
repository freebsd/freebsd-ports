--- packages/clib/uuid.c.orig	2026-06-17 21:36:40 UTC
+++ packages/clib/uuid.c
@@ -137,9 +137,9 @@ pl_uuid(term_t UUID, term_t options)
   { case UUID_MAKE_V1:
     case UUID_MAKE_MC:
     case UUID_MAKE_V4:
-      uuid_create(&uuid);
-      if ( (urc=uuid_make(uuid, mode)) != UUID_RC_OK )
-	return PL_warning("UUID: make: %s\n", uuid_error(urc));
+      ossp_uuid_create(&uuid);
+      if ( (urc=ossp_uuid_make(uuid, mode)) != UUID_RC_OK )
+	return PL_warning("UUID: make: %s\n", ossp_uuid_error(urc));
       break;
     case UUID_MAKE_V3:
     case UUID_MAKE_V5:
@@ -148,12 +148,12 @@ pl_uuid(term_t UUID, term_t options)
       if ( !ns )
 	return PL_existence_error("uuid_context", options);
 
-      uuid_create(&uuid);
-      uuid_create(&uuid_ns);
-      uuid_load(uuid_ns, ns);
-      if ( (urc=uuid_make(uuid, mode, uuid_ns, str)) != UUID_RC_OK )
-	return PL_warning("UUID: make: %s\n", uuid_error(urc));
-      uuid_destroy(uuid_ns);
+      ossp_uuid_create(&uuid);
+      ossp_uuid_create(&uuid_ns);
+      ossp_uuid_load(uuid_ns, ns);
+      if ( (urc=ossp_uuid_make(uuid, mode, uuid_ns, str)) != UUID_RC_OK )
+	return PL_warning("UUID: make: %s\n", ossp_uuid_error(urc));
+      ossp_uuid_destroy(uuid_ns);
       break;
     }
     default:
@@ -166,8 +166,8 @@ pl_uuid(term_t UUID, term_t options)
     void *ptr = buf;
     size_t datalen = sizeof(buf);
 
-    if ( (urc=uuid_export(uuid, UUID_FMT_STR, &ptr, &datalen)) != UUID_RC_OK )
-      return PL_warning("UUID: export: %s\n", uuid_error(urc));
+    if ( (urc=ossp_uuid_export(uuid, UUID_FMT_STR, &ptr, &datalen)) != UUID_RC_OK )
+      return PL_warning("UUID: export: %s\n", ossp_uuid_error(urc));
     rc = PL_unify_chars(UUID, PL_ATOM|REP_ISO_LATIN_1, (size_t)-1, buf);
   } else if ( format == ATOM_integer )
   { char buf[UUID_LEN_SIV+1];
@@ -175,8 +175,8 @@ pl_uuid(term_t UUID, term_t options)
     size_t datalen = sizeof(buf);
     term_t tmp = PL_new_term_ref();
 
-    if ( (urc=uuid_export(uuid, UUID_FMT_SIV, &ptr, &datalen)) != UUID_RC_OK )
-      return PL_warning("UUID: export: %s\n", uuid_error(urc));
+    if ( (urc=ossp_uuid_export(uuid, UUID_FMT_SIV, &ptr, &datalen)) != UUID_RC_OK )
+      return PL_warning("UUID: export: %s\n", ossp_uuid_error(urc));
     rc = ( PL_chars_to_term(buf, tmp) &&
 	   PL_unify(UUID, tmp)
 	 );
@@ -185,7 +185,7 @@ pl_uuid(term_t UUID, term_t options)
     return FALSE;
   }
 
-  uuid_destroy(uuid);
+  ossp_uuid_destroy(uuid);
 
   return rc;
 }
