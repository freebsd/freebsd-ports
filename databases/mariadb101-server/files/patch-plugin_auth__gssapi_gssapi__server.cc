From 3d794d0ee8e0a5a7dfbd3b7de056c0a3ccb9aa81 Mon Sep 17 00:00:00 2001
From: Vladislav Vaintroub <wlad@mariadb.com>

Date: Wed, 6 Jan 2016 09:15:19 +0100
Subject: [PATCH] MDEV9494 Fix build for Heimdal Kerberos
---

 plugin/auth_gssapi/gssapi_server.cc | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/plugin/auth_gssapi/gssapi_server.cc b/plugin/auth_gssapi/gssapi_server.cc
index d325b2a..ed042a0 100644
--- plugin/auth_gssapi/gssapi_server.cc.orig	2016-01-28 12:12:51 UTC
+++ plugin/auth_gssapi/gssapi_server.cc
@@ -58,7 +58,7 @@ static char* get_default_principal_name()
   }
 
   /* Check for entry in keytab */
-  if (krb5_kt_read_service_key(context, NULL, principal, 0, 0, &key))
+  if (krb5_kt_read_service_key(context, NULL, principal, 0, (krb5_enctype)0, &key))
   {
     sql_print_warning("GSSAPI plugin : default principal '%s' not found in keytab", unparsed_name);
     goto cleanup;
