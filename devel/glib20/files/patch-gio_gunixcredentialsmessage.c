--- gio/gunixcredentialsmessage.c.orig	2011-09-25 11:42:09.000000000 -0400
+++ gio/gunixcredentialsmessage.c	2011-09-25 11:42:22.000000000 -0400
@@ -162,11 +162,11 @@ g_unix_credentials_message_deserialize (
       {
         goto out;
       }
-    if (size < CMSG_LEN (sizeof *cred))
+    if (size < sizeof *cred)
       {
         g_warning ("Expected a struct cmsgcred (%" G_GSIZE_FORMAT " bytes) but "
                    "got %" G_GSIZE_FORMAT " bytes of data",
-                   CMSG_LEN (sizeof *cred),
+                   sizeof *cred,
                    size);
         goto out;
       }
