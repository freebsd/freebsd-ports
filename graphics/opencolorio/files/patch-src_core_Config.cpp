--- src/core/Config.cpp.orig	2018-09-04 18:15:21 UTC
+++ src/core/Config.cpp
@@ -324,7 +324,7 @@ OCIO_NAMESPACE_ENTER
                 sanitytext_ = rhs.sanitytext_;
                 
                 cacheids_ = rhs.cacheids_;
-                cacheidnocontext_ = cacheidnocontext_;
+                cacheidnocontext_ = rhs.cacheidnocontext_;
             }
             return *this;
         }
