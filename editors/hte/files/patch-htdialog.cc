$FreeBSD$

--- htdialog.cc.orig	Fri Jun  7 22:00:40 2002
+++ htdialog.cc	Fri Jun  7 22:01:25 2002
@@ -569,7 +569,7 @@
  *	CLASS ht_inputfield
  */
 
-void ht_inputfield::init(bounds *b, int _maxtextlen, ht_list *_history=0)
+void ht_inputfield::init(bounds *b, int _maxtextlen, ht_list *_history)
 {
 	ht_view::init(b, VO_SELECTABLE, "some inputfield");
 	VIEW_DEBUG_NAME("ht_inputfield");
@@ -727,7 +727,7 @@
  *	CLASS ht_strinputfield
  */
 
-void ht_strinputfield::init(bounds *b, int maxstrlen, ht_list *history=0)
+void ht_strinputfield::init(bounds *b, int maxstrlen, ht_list *history)
 {
 	ht_inputfield::init(b, maxstrlen, history);
 	VIEW_DEBUG_NAME("ht_strinputfield");
@@ -1319,7 +1319,7 @@
  *	ht_listbox
  */
 
-void ht_listbox::init(bounds *b, UINT Listboxcaps=LISTBOX_QUICKFIND)
+void ht_listbox::init(bounds *b, UINT Listboxcaps)
 {
 	ht_view::init(b, VO_SELECTABLE | VO_OWNBUFFER | VO_RESIZE, 0);
 
@@ -1784,7 +1784,7 @@
  *	ht_text_listbox
  */
 
-void	ht_text_listbox::init(bounds *b, int Cols, int Keycol, UINT Listboxcaps=LISTBOX_QUICKFIND)
+void	ht_text_listbox::init(bounds *b, int Cols, int Keycol, UINT Listboxcaps)
 {
 	cols = Cols;
 	keycol = Keycol;
@@ -2046,7 +2046,7 @@
  *	CLASS ht_itext_listbox
  */
 
-void	ht_itext_listbox::init(bounds *b, int Cols=1, int Keycol=0)
+void	ht_itext_listbox::init(bounds *b, int Cols, int Keycol)
 {
 	ht_text_listbox::init(b, Cols, Keycol);
 }
