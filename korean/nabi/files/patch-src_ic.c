--- src/ic.c.orig	Sat Aug 23 14:15:05 2003
+++ src/ic.c	Fri Sep 19 10:47:55 2003
@@ -1219,7 +1219,7 @@
      * befor commiting the string. but it makes too many flickering
      * so I first send commit string and then delete preedit string.
      * This makes some problem on gtk2 entry */
-    /* nabi_ic_preedit_clear(ic); */
+    nabi_ic_preedit_clear(ic);
 
     list[0] = buf;
         ret = XwcTextListToTextProperty(server->display, list, 1,
@@ -1237,7 +1237,7 @@
     XFree(tp.value);
 
     /* we delete preedit string here */
-    nabi_ic_preedit_clear(ic);
+    /* nabi_ic_preedit_clear(ic); */
 
     return True;
 }
