--- platform/x11/detect.py.orig	2017-12-28 05:14:45 UTC
+++ platform/x11/detect.py
@@ -52,7 +52,9 @@ def get_opts():
         BoolVariable('use_static_cpp', 'Link stdc++ statically', False),
         BoolVariable('use_sanitizer', 'Use LLVM compiler address sanitizer', False),
         BoolVariable('use_leak_sanitizer', 'Use LLVM compiler memory leaks sanitizer (implies use_sanitizer)', False),
-        BoolVariable('pulseaudio', 'Detect & use pulseaudio', True),
+        BoolVariable('alsa','Detect & Use alsa audio',False),
+        BoolVariable('oss','Detect & Use OSS audio',False),
+        BoolVariable('pulseaudio', 'Detect & Use pulseaudio', False),
         BoolVariable('udev', 'Use udev for gamepad connection callbacks', False),
         EnumVariable('debug_symbols', 'Add debug symbols to release version', 'yes', ('yes', 'no', 'full')),
         BoolVariable('separate_debug_symbols', 'Create a separate file with the debug symbols', False),
@@ -154,7 +156,7 @@ def configure(env):
     # FIXME: Check for existence of the libs before parsing their flags with pkg-config
 
     if not env['builtin_openssl']:
-        env.ParseConfig('pkg-config openssl --cflags --libs')
+        env.ParseConfig('echo -lssl -lcrypto')
 
     if not env['builtin_libwebp']:
         env.ParseConfig('pkg-config libwebp --cflags --libs')
@@ -226,12 +228,18 @@ def configure(env):
 
     ## Flags
 
-    if (os.system("pkg-config --exists alsa") == 0): # 0 means found
-        print("Enabling ALSA")
-        env.Append(CPPFLAGS=["-DALSA_ENABLED"])
-        env.ParseConfig('pkg-config alsa --cflags --libs')
-    else:
-        print("ALSA libraries not found, disabling driver")
+    if env['alsa']:
+        if os.system("pkg-config --exists alsa")==0:
+            print("Enabling ALSA")
+            env.Append(CPPFLAGS=["-DALSA_ENABLED"])
+            env.Append(LIBS=['asound'])
+        else:
+            print("ALSA libraries not found, disabling driver")
+
+    if env['oss']:
+        print("Enabling OSS Audio")
+        env.Append(CPPFLAGS=["-DOSS_ENABLED"])
+        env.Append(CCFLAGS=['-Ithirdparty/rtaudio'])
 
     if env['pulseaudio']:
         if (os.system("pkg-config --exists libpulse-simple") == 0): # 0 means found
