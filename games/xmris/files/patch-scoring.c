--- scoring.c.orig	1995-12-22 12:08:10 UTC
+++ scoring.c
@@ -208,7 +208,7 @@ ARGSEP  uid_t     uid
 	{
 	  if(current_uid != effective_uid)
 	    set_euid((current_uid = effective_uid));
-	  filed = open(locking_file, O_CREAT | O_EXCL, 0666);
+	  filed = open(locking_file, O_CREAT | O_EXCL, 0660);
 	  if(filed >= 0)
 	    break;
 	  if(errno == EINTR)
@@ -259,7 +259,7 @@ ARGSEP  uid_t     uid
 #endif /* USELOCKFILE */
 #ifndef TRANSPUTER
   if(stream && flag & 4 && effective_uid == real_uid)
-    chmod(name, 0666); /* not everyone has fchmod */
+    chmod(name, 0660); /* not everyone has fchmod */
   if(current_uid != real_uid)
     set_euid((current_uid = real_uid));
 #endif /* TRANSPUTER */
