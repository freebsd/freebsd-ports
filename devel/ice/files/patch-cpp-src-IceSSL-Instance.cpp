--- cpp.orig/src/IceSSL/Instance.cpp	2011-06-15 21:43:59.000000000 +0200
+++ cpp/src/IceSSL/Instance.cpp	2012-03-04 20:14:53.000000000 +0100
@@ -38,7 +38,7 @@
 using namespace Ice;
 using namespace IceSSL;
 
-IceUtil::Shared* IceInternal::upCast(IceSSL::Instance* p) { return p; }
+IceUtil::Shared* IceSSL::upCast(IceSSL::Instance* p) { return p; }
 
 namespace
 {
