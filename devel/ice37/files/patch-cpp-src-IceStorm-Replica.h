--- cpp/src/IceStorm/Replica.h.orig	2021-06-21 14:44:58 UTC
+++ cpp/src/IceStorm/Replica.h
@@ -23,7 +23,7 @@ struct GroupNodeInfo
     //
 #if defined(__clang__) && defined(_LIBCPP_VERSION)
 #   ifdef ICE_CPP11_COMPILER
-    GroupNodeInfo(const GroupNodeInfo&);
+    GroupNodeInfo(const GroupNodeInfo&) = default;
 #   endif
     GroupNodeInfo& operator=(const GroupNodeInfo&);
 #endif
