$FreeBSD$

--- src/s_audio.c.orig	Sat Oct 18 05:32:24 2003
+++ src/s_audio.c	Tue Nov 11 22:46:57 2003
@@ -716,7 +716,7 @@ void sys_listdevs(void )
 #endif
     post("unknown API");    
 
-    sys_listmididevs();
+//    sys_listmididevs();
 }
 
 void sys_setblocksize(int n)
