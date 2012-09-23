--- cpp.orig/src/IceUtil/Shared.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/IceUtil/Shared.cpp	2012-09-10 11:43:58.000000000 +0200
@@ -96,6 +96,18 @@ IceUtil::SimpleShared::SimpleShared(const SimpleShared&) :
 {
 }
 
+IceUtil::SimpleSharedUnsafeDestructor::SimpleSharedUnsafeDestructor() :
+    _ref(0),
+    _noDelete(false)
+{
+}
+
+IceUtil::SimpleSharedUnsafeDestructor::SimpleSharedUnsafeDestructor(const SimpleSharedUnsafeDestructor&) :
+    _ref(0),
+    _noDelete(false)
+{
+}
+
 IceUtil::Shared::Shared() :
     _ref(0),
     _noDelete(false)
