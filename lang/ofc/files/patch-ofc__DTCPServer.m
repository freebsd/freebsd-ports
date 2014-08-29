--- ./ofc/DTCPServer.m.orig	2008-08-11 18:59:46.000000000 +0200
+++ ./ofc/DTCPServer.m	2014-08-29 08:26:49.887997880 +0200
@@ -370,6 +370,7 @@
           {
             switch(_mode)
             {
+#ifndef __FreeBSD__
              case DTS_THREADING:
               {
                 ok = (objc_thread_detach(@selector(handleConnection:), self, peer) != NULL);
@@ -380,6 +381,7 @@
                 }
               }
               break;
+#endif
 #ifndef WIN32                
              case DTS_FORKING:
               {
@@ -460,9 +462,11 @@
   
   switch(_mode)
   {
+#ifndef __FreeBSD__
    case DTS_THREADING:
     objc_thread_exit();
     break;
+#endif
     
    case DTS_FORKING:
     exit(0);
