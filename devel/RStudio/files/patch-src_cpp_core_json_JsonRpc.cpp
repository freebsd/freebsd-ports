--- src/cpp/core/json/JsonRpc.cpp.orig	2024-10-10 06:06:47 UTC
+++ src/cpp/core/json/JsonRpc.cpp
@@ -193,7 +193,7 @@ bool JsonRpcResponse::hasAfterResponse() const
    
 bool JsonRpcResponse::hasAfterResponse() const
 {
-   return afterResponse_;
+   return (bool)afterResponse_;
 }
    
    
