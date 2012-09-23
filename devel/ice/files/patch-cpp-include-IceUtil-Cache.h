--- cpp.orig/include/IceUtil/Cache.h	2011-06-15 21:43:58.000000000 +0200
+++ cpp/include/IceUtil/Cache.h	2012-09-10 11:43:58.000000000 +0200
@@ -77,6 +77,6 @@ protected:
     {
     }
     
-    virtual ~Cache()
+    virtual ~Cache() ICE_NOEXCEPT_FALSE
     {
     }
