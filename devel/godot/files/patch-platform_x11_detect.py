--- platform/x11/detect.py.orig	2014-12-15 21:49:18.000000000 +0300
+++ platform/x11/detect.py	2015-03-03 07:01:34.000000000 +0300
@@ -29,11 +29,6 @@
 		print("X11 not found.. x11 disabled.")
 		return False
 
-        ssl_error=os.system("pkg-config openssl --modversion > /dev/null ")
-        if (ssl_error):
-                print("OpenSSL not found.. x11 disabled.")
-                return False
-
 	x11_error=os.system("pkg-config xcursor --modversion > /dev/null ")
 	if (x11_error):
 		print("xcursor not found.. x11 disabled.")
@@ -72,17 +67,16 @@
 
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
@@ -105,7 +99,7 @@
 
 	env.ParseConfig('pkg-config x11 --cflags --libs')
 	env.ParseConfig('pkg-config xcursor --cflags --libs')
-	env.ParseConfig('pkg-config openssl --cflags --libs')
+	env.ParseConfig('echo -lssl -lcrypto')
 
 
 	env.ParseConfig('pkg-config freetype2 --cflags --libs')
@@ -128,11 +122,6 @@
 		env.Append(LINKFLAGS=['-m64','-L/usr/lib/i686-linux-gnu'])
 
 
-	if (env["CXX"]=="clang++"):
-		env.Append(CPPFLAGS=['-DTYPED_METHOD_BIND'])
-		env["CC"]="clang"
-		env["LD"]="clang++"
-
 	import methods
 
 	env.Append( BUILDERS = { 'GLSL120' : env.Builder(action = methods.build_legacygl_headers, suffix = 'glsl.h',src_suffix = '.glsl') } )
