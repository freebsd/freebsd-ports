--- platform/x11/detect.py.orig	2014-12-16 05:19:18.000000000 +1030
+++ platform/x11/detect.py	2015-01-23 16:08:21.497280349 +1030
@@ -72,17 +72,16 @@
 
 	env.Append(CPPPATH=['#platform/x11'])
 	if (env["use_llvm"]=="yes"):
-		env["CC"]="clang"
-		env["CXX"]="clang++"
-		env["LD"]="clang++"
-		if (env["use_sanitizer"]=="yes"):
-			env.Append(CXXFLAGS=['-fsanitize=address','-fno-omit-frame-pointer'])
-			env.Append(LINKFLAGS=['-fsanitize=address'])
-			env.extra_suffix=".llvms"
-		else:
-			env.extra_suffix=".llvm"
-
-
+		if 'clang++' not in env['CXX']:
+			env["CC"]="clang"
+			env["CXX"]="clang++"
+			env["LD"]="clang++"
+			env.Append(CPPFLAGS=['-DTYPED_METHOD_BIND'])
+		env.extra_suffix=".llvm"
+
+	if (env["use_sanitizer"]=="yes"):
+		env.Append(CCFLAGS=['-fsanitize=address','-fno-omit-frame-pointer'])
+		env.Append(LINKFLAGS='-fsanitize=address')
 
 
 	#if (env["tools"]=="no"):
@@ -128,11 +127,6 @@
 		env.Append(LINKFLAGS=['-m64','-L/usr/lib/i686-linux-gnu'])
 
 
-	if (env["CXX"]=="clang++"):
-		env.Append(CPPFLAGS=['-DTYPED_METHOD_BIND'])
-		env["CC"]="clang"
-		env["LD"]="clang++"
-
 	import methods
 
 	env.Append( BUILDERS = { 'GLSL120' : env.Builder(action = methods.build_legacygl_headers, suffix = 'glsl.h',src_suffix = '.glsl') } )
