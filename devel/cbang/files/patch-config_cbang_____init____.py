--- config/cbang/__init__.py.orig	2021-08-10 22:46:49 UTC
+++ config/cbang/__init__.py
@@ -99,6 +99,7 @@ def configure(conf):
 
     conf.CBRequireLib('cbang-boost')
     conf.CBRequireLib('cbang')
+    conf.CBRequireLib('sysinfo')
     conf.CBRequireCXXHeader('cbang/Exception.h')
     env.CBDefine('HAVE_CBANG')
 
