--- cpp/src/Freeze/SharedDbEnv.cpp.orig	2019-08-12 19:54:18 UTC
+++ cpp/src/Freeze/SharedDbEnv.cpp
@@ -530,7 +530,7 @@ Freeze::SharedDbEnv::SharedDbEnv(const std::string& en
     {
         if(_env == 0)
         {
-            _envHolder.reset(new DbEnv(0));
+            _envHolder.reset(new DbEnv((u_int32_t)0));
             _env = _envHolder.get();
 
             if(_trace >= 1)
