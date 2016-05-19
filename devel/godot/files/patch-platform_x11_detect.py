--- platform/x11/detect.py.orig	2016-02-29 16:49:54 UTC
+++ platform/x11/detect.py
@@ -30,11 +30,6 @@ def can_build():
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
@@ -133,7 +128,7 @@ def configure(env):
 	env.ParseConfig('pkg-config xcursor --cflags --libs')
 
 	if (env["openssl"]=="yes"):
-		env.ParseConfig('pkg-config openssl --cflags --libs')
+		env.ParseConfig('echo -lssl -lcrypto')
 
 
 	if (env["freetype"]=="yes"):
