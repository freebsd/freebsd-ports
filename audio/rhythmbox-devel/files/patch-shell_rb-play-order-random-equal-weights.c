--- shell/rb-play-order-random-equal-weights.c.orig	Thu Dec 18 02:59:09 2003
+++ shell/rb-play-order-random-equal-weights.c	Thu Dec 18 02:59:16 2003
@@ -85,6 +85,7 @@
 rb_random_play_order_equal_weights_class_init (RBRandomPlayOrderEqualWeightsClass *klass)
 {
 	GObjectClass *object_class = G_OBJECT_CLASS (klass);
+	RBPlayOrderClass *porder = RB_PLAY_ORDER_CLASS (klass);
 
 	parent_class = g_type_class_peek_parent (klass);
 
@@ -92,7 +93,6 @@
 	object_class->finalize = rb_random_play_order_equal_weights_finalize;
 
 
-	RBPlayOrderClass *porder = RB_PLAY_ORDER_CLASS (klass);
 	porder->get_next = rb_random_play_order_equal_weights_get_next;
 	porder->go_next = rb_random_play_order_equal_weights_go_next;
 	porder->get_previous = rb_random_play_order_equal_weights_get_previous;
