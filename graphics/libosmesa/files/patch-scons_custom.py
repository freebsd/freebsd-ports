--- scons/custom.py.orig	2012-10-10 16:32:44.000000000 +0200
+++ scons/custom.py	2012-10-10 16:32:29.000000000 +0200
@@ -301,6 +301,8 @@
     createPkgConfigMethods(env)
     createParseSourceListMethod(env)
 
+    env['LEX'] = '%%LOCALBASE%%/bin/flex'
+
     # for debugging
     #print env.Dump()
 
