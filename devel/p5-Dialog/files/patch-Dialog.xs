--- Dialog.xs.orig	Thu Apr  5 11:38:53 2007
+++ Dialog.xs	Thu Apr  5 11:39:07 2007
@@ -309,6 +309,7 @@
 	uchar **item_list, **item_ptr, *item;
 	uchar *result;
 	size_t size = 0, tmpsz, len;
+	STRLEN na;
 	PPCODE:
 	item_no = items - 5;
 	New(0,item_list,2 * item_no,uchar*);
@@ -341,6 +342,7 @@
 	uchar **item_list, **item_ptr, *item;
 	uchar *result, *strb, *stre;
 	size_t size = 1, len;
+	STRLEN na;
 	PPCODE:
 	item_no = items - 5;
 	New(0,item_list,3 * item_no,uchar*);
@@ -381,6 +383,7 @@
 	uchar **item_list, **item_ptr, *item;
 	uchar *result;
 	size_t size = 0, tmpsz, len;
+	STRLEN na;
 	PPCODE:
 	item_no = items - 5;
 	New(0,item_list,3 * item_no,uchar*);
