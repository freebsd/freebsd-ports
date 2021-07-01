--- ppp/ppp_l2tp_ctrl.c.orig	2009-05-13 21:36:03 UTC
+++ ppp/ppp_l2tp_ctrl.c
@@ -167,7 +167,7 @@ struct ppp_l2tp_sess {
 	u_int16_t		peer_id;		/* peer session id */
 	struct ppp_log		*log;			/* log */
 	ng_ID_t			node_id;		/* tee node id */
-	char			hook[NG_HOOKLEN + 1];	/* session hook name */
+	char			hook[NG_HOOKSIZ];	/* session hook name */
 	void			*link_cookie;		/* opaque link cookie */
 	u_int16_t		result;			/* close result code */
 	u_int16_t		error;			/* close error code */
@@ -575,7 +575,7 @@ ppp_l2tp_ctrl_create(struct pevent_ctx *ctx, pthread_m
 
 	/* Done */
 	*nodep = ctrl->node_id;
-	strlcpy(hook, NG_L2TP_HOOK_LOWER, NG_HOOKLEN + 1);
+	strlcpy(hook, NG_L2TP_HOOK_LOWER, NG_HOOKSIZ);
 	return (ctrl);
 
 fail:
@@ -1827,7 +1827,7 @@ ppp_l2tp_ctrl_event(void *arg)
 	    struct ng_mesg msg;
 	} buf;
 	struct ng_mesg *const msg = &buf.msg;
-	char raddr[NG_PATHLEN + 1];
+	char raddr[NG_PATHSIZ];
 	int len;
 
 	/* Read netgraph control message */
