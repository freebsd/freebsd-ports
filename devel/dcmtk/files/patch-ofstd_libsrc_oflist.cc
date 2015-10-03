--- ofstd/libsrc/oflist.cc.orig	2015-05-30 20:13:25 UTC
+++ ofstd/libsrc/oflist.cc
@@ -50,8 +50,8 @@ OFListBase::OFListBase()
 OFListBase::~OFListBase()
 {
     base_clear();
-    if (afterLast)
-        delete afterLast;
+    delete afterLast;
+    afterLast = NULL;
 }
 
 OFListLinkBase * OFListBase::base_insert(OFListLinkBase * pos,
