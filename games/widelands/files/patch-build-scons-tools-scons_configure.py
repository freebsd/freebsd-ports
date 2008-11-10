--- build/scons-tools/scons_configure.py.orig	2008-10-05 18:59:26.000000000 +0400
+++ build/scons-tools/scons_configure.py	2008-11-10 01:24:38.000000000 +0300
@@ -439,16 +439,16 @@
 	conf.CheckCompilerFlag('-fbounds-check', env)
 	conf.CheckCompilerFlag('-pipe', env)
 
-	if env.optimize:
-		# !!!! -fomit-frame-pointer breaks execeptions !!!!
-		conf.CheckCompilerFlag('-fexpensive-optimizations', env)
-		conf.CheckCompilerFlag('-finline-functions', env)
-		conf.CheckCompilerFlag('-ffast-math', env)
-		conf.CheckCompilerFlag('-funroll-loops', env)
-		conf.CheckCompilerFlag('-O3', env)
-	else:
-		conf.CheckCompilerFlag('-O0', env)
-		conf.CheckCompilerFlag('-funit-at-a-time', env)
+#	if env.optimize:
+#		# !!!! -fomit-frame-pointer breaks execeptions !!!!
+#		conf.CheckCompilerFlag('-fexpensive-optimizations', env)
+#		conf.CheckCompilerFlag('-finline-functions', env)
+#		conf.CheckCompilerFlag('-ffast-math', env)
+#		conf.CheckCompilerFlag('-funroll-loops', env)
+#		conf.CheckCompilerFlag('-O3', env)
+#	else:
+#		conf.CheckCompilerFlag('-O0', env)
+#		conf.CheckCompilerFlag('-funit-at-a-time', env)
 
 	if env.profile:
 		conf.CheckCompilerFlag('-pg', env)
