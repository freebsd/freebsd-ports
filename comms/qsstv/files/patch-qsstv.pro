--- qsstv.pro.orig	2021-07-31 20:57:03 UTC
+++ qsstv.pro
@@ -523,7 +523,7 @@ QMAKE_EXTRA_TARGETS   +=   dox
 
 
 isEmpty(PREFIX) {
-        PREFIX = /usr/local
+        PREFIX = %%PREFIX%%
     }
 target.path = $$PREFIX/bin
 
