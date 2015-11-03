--- sope-appserver/NGObjWeb/WOHttpAdaptor/WOHttpAdaptor.m.orig	2015-09-16 18:26:49 UTC
+++ sope-appserver/NGObjWeb/WOHttpAdaptor/WOHttpAdaptor.m
@@ -427,7 +427,7 @@ static BOOL     debugOn                 
 }
 
 - (NGActiveSocket *)_accept {
-  NGActiveSocket *connection;
+  id<NGActiveSocket>  connection;
   id<NGSocketAddress> remote;
 
   NS_DURING {
@@ -450,7 +450,7 @@ static BOOL     debugOn                 
   }
   NS_ENDHANDLER;
 
-  return connection;
+  return (NGActiveSocket*)connection;
 }
 
 - (void)_handleConnection:(NGActiveSocket *)connection {
