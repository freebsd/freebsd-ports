--- shell/rb-play-order-random-by-age.c.orig	Thu Dec 18 02:59:50 2003
+++ shell/rb-play-order-random-by-age.c	Thu Dec 18 03:00:34 2003
@@ -87,6 +87,7 @@
 rb_random_play_order_by_age_class_init (RBRandomPlayOrderByAgeClass *klass)
 {
 	GObjectClass *object_class = G_OBJECT_CLASS (klass);
+	RBPlayOrderClass *porder = RB_PLAY_ORDER_CLASS (klass);
 
 	parent_class = g_type_class_peek_parent (klass);
 
@@ -94,7 +95,6 @@
 	object_class->finalize = rb_random_play_order_by_age_finalize;
 
 
-	RBPlayOrderClass *porder = RB_PLAY_ORDER_CLASS (klass);
 	porder->get_next = rb_random_play_order_by_age_get_next;
 	porder->go_next = rb_random_play_order_by_age_go_next;
 	porder->get_previous = rb_random_play_order_by_age_get_previous;
@@ -265,6 +265,8 @@
 	RhythmDBEntry *result = NULL;
 	GArray *entries = get_entry_view_contents (entry_view);
 	int i;
+	double rnd;
+	double total_weight = 0;
 
 	if (entries->len == 0) {
 		/* entry view empty */
@@ -273,11 +275,10 @@
 
 	/* Algorithm due to treed */
 
-	double total_weight = 0;
 	for (i=0; i<entries->len; ++i) {
 		total_weight += g_array_index (entries, EntryWeight, i).weight;
 	}
-	double rnd = g_random_double_range (0, total_weight);
+	rnd = g_random_double_range (0, total_weight);
 	for (i=0; i<entries->len; ++i) {
 		if (rnd < g_array_index (entries, EntryWeight, i).weight) {
 			result = g_array_index (entries, EntryWeight, i).entry;
