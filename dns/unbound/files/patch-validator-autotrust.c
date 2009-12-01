Index: validator/autotrust.c
===================================================================
--- validator/autotrust.c	(revision 1923)
+++ validator/autotrust.c	(revision 1924)
@@ -100,6 +100,8 @@
 autr_get_num_anchors(struct val_anchors* anchors)
 {
 	size_t res = 0;
+	if(!anchors)
+		return 0;
 	lock_basic_lock(&anchors->lock);
 	if(anchors->autr)
 		res = anchors->autr->probe.count;
