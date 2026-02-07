--- ppp/ppp_node.c.orig	2009-05-13 21:36:03 UTC
+++ ppp/ppp_node.c
@@ -398,7 +398,7 @@ int
 ppp_node_send_msg(struct ppp_node *node, const char *relpath,
 	u_int32_t cookie, u_int32_t cmd, const void *payload, size_t plen)
 {
-	char path[NG_PATHLEN + 1];
+	char path[NG_PATHSIZ];
 
 	if (relpath == NULL)
 		strlcpy(path, NODE_HOOK, sizeof(path));
@@ -465,7 +465,7 @@ ppp_node_read_message(void *arg)
 {
 	struct ppp_node *const node = arg;
 	const size_t max_msglen = 4096;
-	char raddr[NG_PATHLEN + 1];
+	char raddr[NG_PATHSIZ];
 	struct ppp_node_recvmsg *rm;
 	struct ng_mesg *msg;
 	int found = 0;
