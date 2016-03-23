--- lib/ipc_int.h.orig	2015-08-18 19:55:43 UTC
+++ lib/ipc_int.h
@@ -91,6 +91,7 @@ struct qb_ipcc_funcs {
 struct qb_ipcc_connection {
 	char name[NAME_MAX];
 	int32_t needs_sock_for_poll;
+	gid_t egid;
 	struct qb_ipc_one_way setup;
 	struct qb_ipc_one_way request;
 	struct qb_ipc_one_way response;
