--- platform/x11/detect.py.orig	2016-11-15 18:44:21 UTC
+++ platform/x11/detect.py
@@ -31,11 +31,6 @@ def can_build():
         print("X11 not found.. x11 disabled.")
         return False
 
-    ssl_error = os.system("pkg-config openssl --modversion > /dev/null ")
-    if (ssl_error):
-        print("OpenSSL not found.. x11 disabled.")
-        return False
-
     x11_error = os.system("pkg-config xcursor --modversion > /dev/null ")
     if (x11_error):
         print("xcursor not found.. x11 disabled.")
@@ -61,7 +56,9 @@ def get_opts():
         ('use_static_cpp', 'link stdc++ statically', 'no'),
         ('use_sanitizer', 'Use llvm compiler sanitize address', 'no'),
         ('use_leak_sanitizer', 'Use llvm compiler sanitize memory leaks', 'no'),
-        ('pulseaudio', 'Detect & Use pulseaudio', 'yes'),
+        ('alsa','Detect & Use alsa audio','no'),
+        ('oss','Detect & Use OSS audio','no'),
+        ('pulseaudio', 'Detect & Use pulseaudio', 'no'),
         ('udev', 'Use udev for gamepad connection callbacks', 'no'),
         ('debug_release', 'Add debug symbols to release version', 'no'),
     ]
@@ -134,7 +131,7 @@ def configure(env):
     env.ParseConfig('pkg-config xrandr --cflags --libs')
 
     if (env['builtin_openssl'] == 'no'):
-        env.ParseConfig('pkg-config openssl --cflags --libs')
+        env.ParseConfig('echo -lssl -lcrypto')
 
     if (env['builtin_libwebp'] == 'no'):
         env.ParseConfig('pkg-config libwebp --cflags --libs')
@@ -173,12 +170,13 @@ def configure(env):
     if (env['builtin_glew'] == 'no'):
         env.ParseConfig('pkg-config glew --cflags --libs')
 
-    if os.system("pkg-config --exists alsa") == 0:
-        print("Enabling ALSA")
-        env.Append(CPPFLAGS=["-DALSA_ENABLED"])
-        env.ParseConfig('pkg-config alsa --cflags --libs')
-    else:
-        print("ALSA libraries not found, disabling driver")
+    if (env["alsa"]=="yes"):
+        if os.system("pkg-config --exists alsa")==0:
+            print("Enabling ALSA")
+            env.Append(CPPFLAGS=["-DALSA_ENABLED"])
+            env.Append(LIBS=['asound'])
+        else:
+            print("ALSA libraries not found, disabling driver")
 
     if (platform.system() == "Linux"):
         env.Append(CPPFLAGS=["-DJOYDEV_ENABLED"])
@@ -193,6 +191,11 @@ def configure(env):
         else:
             print("libudev development libraries not found, disabling udev support")
 
+    if (env["oss"]=="yes"):
+        print("Enabling OSS Audio")
+        env.Append(CPPFLAGS=["-DOSS_ENABLED"])
+        env.Append(CCFLAGS=['-Ithirdparty/rtaudio'])
+
     if (env["pulseaudio"] == "yes"):
         if not os.system("pkg-config --exists libpulse-simple"):
             print("Enabling PulseAudio")
