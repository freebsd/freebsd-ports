--- src/iassrv.c.orig	Sun Dec 16 19:22:20 2001
+++ src/iassrv.c	Wed Jul 16 14:08:55 2003
@@ -281,6 +281,7 @@
 
 static void status(Connection* con, int event, void* buf, int len)
 {
+  int flags;
   IASConnection* ic=(IASConnection*)con->handle;
 
   if(event==CONN_CLOSED) {
@@ -300,9 +301,10 @@
 
     if(ic->outBuf) freeMem(ic->outBuf);
     if(ic->inBuf) freeMem(ic->inBuf);
+    flags = ic->ias->ias.debug&IAS_DEBUG_INFO;
     freeMem(ic);
     connClose(con);
-    if(ic->ias->ias.debug&IAS_DEBUG_INFO) log("ias closed\n");
+    if(flags) log("ias closed\n");
   }
 }
 
