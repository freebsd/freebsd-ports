$FreeBDS$

--- blockop.cc.orig	Fri Jun  7 21:56:30 2002
+++ blockop.cc	Fri Jun  7 21:56:36 2002
@@ -41,7 +41,7 @@
  *	CLASS ht_blockop_dialog
  */
 
-void ht_blockop_dialog::init(bounds *b, FILEOFS pstart, FILEOFS pend, ht_list *history=0)
+void ht_blockop_dialog::init(bounds *b, FILEOFS pstart, FILEOFS pend, ht_list *history)
 {
 	ht_dialog::init(b, "operate on block", FS_TITLE | FS_KILLER | FS_MOVE);
 	bounds c;
