--- src/ui/ncurses/uitagbrowser.cc.old	Wed Aug  4 08:22:13 2004
+++ src/ui/ncurses/uitagbrowser.cc	Wed Aug  4 08:22:30 2004
@@ -83,7 +83,7 @@
     cm.setwindow(textwindow(w.x1, w.y1, w.x1+20, 0, uiconf.getcolor(cp_menufr)));
 
     for(motortagbrowser::viewscope scope = motortagbrowser::File;
-    scope != motortagbrowser::viewscope_size; (int) scope += 1) {
+    scope != motortagbrowser::viewscope_size; (int&) scope += 1) {
 	cm.additem(0, scope, (string) " " + getscopename(scope));
 	if(scope == tagbrowser.getscope())
 	    cm.setpos(cm.getcount()-1);
