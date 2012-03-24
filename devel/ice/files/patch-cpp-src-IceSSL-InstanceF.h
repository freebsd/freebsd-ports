--- cpp.orig/src/IceSSL/InstanceF.h	2011-06-15 21:43:59.000000000 +0200
+++ cpp/src/IceSSL/InstanceF.h	2012-03-04 20:14:53.000000000 +0100
@@ -18,13 +18,13 @@
 {
 
 class Instance;
+IceUtil::Shared* upCast(IceSSL::Instance*);
 
 }
 
 namespace IceInternal
 {
 
-IceUtil::Shared* upCast(IceSSL::Instance*);
 
 }
 
