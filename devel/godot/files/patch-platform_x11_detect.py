--- platform/x11/detect.py.orig	2015-05-21 18:03:21 UTC
+++ platform/x11/detect.py
@@ -29,11 +29,6 @@ def can_build():
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
@@ -126,7 +121,7 @@ def configure(env):
 	env.ParseConfig('pkg-config x11 --cflags --libs')
 	env.ParseConfig('pkg-config xinerama --cflags --libs')
 	env.ParseConfig('pkg-config xcursor --cflags --libs')
-	env.ParseConfig('pkg-config openssl --cflags --libs')
+	env.ParseConfig('echo -lssl -lcrypto')
 
 
 	env.ParseConfig('pkg-config freetype2 --cflags --libs')
