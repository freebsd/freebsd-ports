--- ppp/ppp_l2tp_ctrl.h.orig	2009-05-13 21:36:03 UTC
+++ ppp/ppp_l2tp_ctrl.h
@@ -168,7 +168,7 @@ __BEGIN_DECLS
  *	peer_id	Unique identifier for peer (used for tie-breakers)
  *	initiate Whether to send a SCCRQ or just wait for one
  *	nodep	Pointer to netgraph node ID variable
- *	hook	Buffer for hook on L2TP netgraph node (size >= NG_HOOKLEN + 1)
+ *	hook	Buffer for hook on L2TP netgraph node (size >= NG_HOOKSIZ)
  *	avps	List of AVP's to include in the associated
  *		Start-Control-Connection-Request or
  *		Start-Control-Connection-Reply control message.
