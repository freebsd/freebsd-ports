--- linkedlist.h	Tue Sep  7 06:32:48 2004
+++ linkedlist.h	Tue Sep  7 06:33:00 2004
@@ -121,7 +121,7 @@
 int linkedList<ItemType>::add(ItemType Item, int location) {
 	node* parent;
 	node* nextspot;
-	if(!find(location, root_, parent)) return 0;
+	if(!find(location, root, parent)) return 0;
 	nextspot = parent->next;
 	parent->next = new node;
 	parent->next->next = nextspot;
