--- shell/rb-play-order-shuffle.c.orig	Thu Dec 18 02:58:17 2003
+++ shell/rb-play-order-shuffle.c	Thu Dec 18 02:58:34 2003
@@ -111,13 +111,13 @@
 rb_shuffle_play_order_class_init (RBShufflePlayOrderClass *klass)
 {
 	GObjectClass *object_class = G_OBJECT_CLASS (klass);
+	RBPlayOrderClass *porder = RB_PLAY_ORDER_CLASS (klass);
 
 	parent_class = g_type_class_peek_parent (klass);
 
 	object_class->constructor = rb_shuffle_play_order_constructor;
 	object_class->finalize = rb_shuffle_play_order_finalize;
 
-	RBPlayOrderClass *porder = RB_PLAY_ORDER_CLASS (klass);
 	porder->get_next = rb_shuffle_play_order_get_next;
 	porder->go_next = rb_shuffle_play_order_go_next;
 	porder->get_previous = rb_shuffle_play_order_get_previous;
