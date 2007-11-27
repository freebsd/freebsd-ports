--- src/client/controls/keymapper_bindings.h.orig	2007-11-27 14:19:00.000000000 +0100
+++ src/client/controls/keymapper_bindings.h	2007-11-27 14:19:25.000000000 +0100
@@ -112,7 +112,7 @@
 	/*! Find a key based on a mouse button
 	    @param button The number of the button
 	    @return Returns the iterator */
-	iterator Evtmapper_bindings::find_by_mouse_button(int button);
+	iterator find_by_mouse_button(int button);
 	/*! Find a key based on its command function
 	    @param cmdfunction The commandfunction we are searching for
 	    @return Returns the iterator*/
