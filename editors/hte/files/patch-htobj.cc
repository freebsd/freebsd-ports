$FreeBSD$

--- htobj.cc.orig	Fri Jun  7 22:15:43 2002
+++ htobj.cc	Fri Jun  7 22:15:56 2002
@@ -672,7 +672,7 @@
 	sendmsg(&m);
 }
 
-void ht_view::sendmsg(int msg, int data1=0, int data2=0)
+void ht_view::sendmsg(int msg, int data1, int data2)
 {
 	htmsg m;
 	switch (msg) {
@@ -1419,7 +1419,7 @@
  *	CLASS ht_frame
  */
 
-void ht_frame::init(bounds *b, char *desc, UINT _style, UINT _number=0)
+void ht_frame::init(bounds *b, char *desc, UINT _style, UINT _number)
 {
 	ht_view::init(b, VO_RESIZE, desc);
 	VIEW_DEBUG_NAME("ht_frame");
