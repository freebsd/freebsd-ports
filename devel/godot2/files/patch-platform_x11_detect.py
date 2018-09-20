--- platform/x11/detect.py.orig	2018-07-29 00:47:52 UTC
+++ platform/x11/detect.py
@@ -56,7 +56,9 @@ def get_opts():
         ('use_sanitizer', 'Use llvm compiler sanitize address', 'no'),
         ('use_leak_sanitizer', 'Use llvm compiler sanitize memory leaks', 'no'),
         ('use_lto', 'Use link time optimization', 'no'),
-        ('pulseaudio', 'Detect & Use pulseaudio', 'yes'),
+        ('alsa','Detect & Use alsa audio','no'),
+        ('oss','Detect & Use OSS audio','no'),
+        ('pulseaudio', 'Detect & Use pulseaudio', 'no'),
         ('udev', 'Use udev for gamepad connection callbacks', 'no'),
         ('debug_release', 'Add debug symbols to release version', 'no'),
         ('touch', 'Enable touch events', 'yes'),
@@ -85,10 +87,6 @@ def configure(env):
 
     env.Append(CPPPATH=['#platform/x11'])
     if (env["use_llvm"] == "yes"):
-        if 'clang++' not in env['CXX']:
-            env["CC"] = "clang"
-            env["CXX"] = "clang++"
-            env["LD"] = "clang++"
         env.Append(CPPFLAGS=['-DTYPED_METHOD_BIND'])
         env.extra_suffix = ".llvm"
     elif (os.system("gcc --version > /dev/null 2>&1") == 0): # GCC
@@ -126,19 +124,14 @@ def configure(env):
     env.Append(LINKFLAGS=['-pipe'])
 
     if (env["target"] == "release"):
-        env.Prepend(CCFLAGS=['-Ofast'])
-        if (env["debug_release"] == "yes"):
-            env.Prepend(CCFLAGS=['-g2'])
+        pass
 
     elif (env["target"] == "release_debug"):
-
-        env.Prepend(CCFLAGS=['-O2', '-ffast-math', '-DDEBUG_ENABLED'])
-        if (env["debug_release"] == "yes"):
-            env.Prepend(CCFLAGS=['-g2'])
-
+        env.Prepend(CCFLAGS=['-DDEBUG_ENABLED'])
+        
     elif (env["target"] == "debug"):
 
-        env.Prepend(CCFLAGS=['-g2', '-DDEBUG_ENABLED', '-DDEBUG_MEMORY_ENABLED'])
+        env.Prepend(CCFLAGS=['-DDEBUG_ENABLED', '-DDEBUG_MEMORY_ENABLED'])
         env.Append(LINKFLAGS=['-rdynamic'])
 
     env.ParseConfig('pkg-config x11 --cflags --libs')
@@ -155,7 +148,12 @@ def configure(env):
         env.Append(CPPFLAGS=['-DTOUCH_ENABLED'])
 
     if (env['builtin_openssl'] == 'no'):
-        env.ParseConfig('pkg-config openssl --cflags --libs')
+        try:
+            # try to find a port installed openssl
+            env.ParseConfig('pkg-config openssl --cflags --libs')
+        except:
+            # if none found use base system openssl
+            env.ParseConfig('echo -lssl -lcrypto')
 
     if (env['builtin_libwebp'] == 'no'):
         env.ParseConfig('pkg-config libwebp --cflags --libs')
@@ -200,12 +198,13 @@ def configure(env):
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
@@ -220,6 +219,11 @@ def configure(env):
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
