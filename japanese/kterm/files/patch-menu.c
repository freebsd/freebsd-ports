--- menu.c.orig	2016-11-04 21:41:21 UTC
+++ menu.c
@@ -843,6 +843,7 @@ static void do_jismode (gw, closure, data)
     update_eucmode();
     update_sjismode();
     update_utf8mode();
+    make_unicode_map();
 }
 
 
@@ -867,6 +868,7 @@ static void do_eucmode (gw, closure, data)
 	update_eucmode();
 	update_sjismode();
 	update_utf8mode();
+	make_unicode_map();
     }
 }
 
@@ -891,6 +893,7 @@ static void do_sjismode (gw, closure, data)
 	update_eucmode();
 	update_sjismode();
 	update_utf8mode();
+	make_unicode_map();
     }
 }
 
