--- shell/rb-play-order.c.orig	Thu Dec 18 02:57:29 2003
+++ shell/rb-play-order.c	Thu Dec 18 02:57:41 2003
@@ -195,9 +195,9 @@
 rb_play_order_get_entry_view (RBPlayOrder *porder)
 {
 	RBShellPlayer *player = porder->priv->player;
+	RBSource *source = rb_shell_player_get_source (player);
 	if (player == NULL)
 		return NULL;
-	RBSource *source = rb_shell_player_get_source (player);
 	if (source == NULL)
 		return NULL;
 	return rb_source_get_entry_view (source);
