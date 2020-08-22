--- client.c.orig	2016-02-06 22:25:25 UTC
+++ client.c
@@ -33,6 +33,8 @@
 #include "cvs.h"
 #include "remote.h"
 
+extern struct cvs_var_head cvs_variables;
+
 struct cvs_req cvs_requests[] = {
 	/* this is what our client will use, the server should support it */
 	{ "Root",		1,	cvs_server_root, REQ_NEEDED },
