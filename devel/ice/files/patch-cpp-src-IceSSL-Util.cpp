--- cpp.orig/src/IceSSL/Util.cpp	2011-06-15 21:43:59.000000000 +0200
+++ cpp/src/IceSSL/Util.cpp	2012-03-04 20:14:53.000000000 +0100
@@ -175,7 +175,7 @@
     return dh;
 }
 
-IceUtil::Shared* IceInternal::upCast(IceSSL::DHParams* p) { return p; }
+IceUtil::Shared* IceSSL::upCast(IceSSL::DHParams* p) { return p; }
 
 IceSSL::DHParams::DHParams() :
     _dh512(0), _dh1024(0), _dh2048(0), _dh4096(0)
