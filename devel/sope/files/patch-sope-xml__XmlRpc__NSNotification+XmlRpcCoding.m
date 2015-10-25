--- sope-xml/XmlRpc/NSNotification+XmlRpcCoding.m.orig	2015-09-16 18:26:50 UTC
+++ sope-xml/XmlRpc/NSNotification+XmlRpcCoding.m
@@ -30,7 +30,7 @@
 }
 
 + (id)decodeObjectWithXmlRpcCoder:(XmlRpcDecoder *)_coder {
-  self = [NSNotification notificationWithName:
+  self = (id)[NSNotification notificationWithName:
                            [_coder decodeStringForKey:@"name"]
                          object:[_coder decodeObjectForKey:@"object"]
                          userInfo:[_coder decodeStructForKey:@"userInfo"]];
