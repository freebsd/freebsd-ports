--- media/ffmpeg/scripts/build_ffmpeg.py.orig	2024-06-18 21:43:35 UTC
+++ media/ffmpeg/scripts/build_ffmpeg.py
@@ -33,7 +33,7 @@ sys.path.append(os.path.join(CHROMIUM_ROOT_DIR, 'build
 SUCCESS_TOKEN = 'THIS_BUILD_WORKED'
 
 sys.path.append(os.path.join(CHROMIUM_ROOT_DIR, 'build'))
-import gn_helpers
+#import gn_helpers
 
 BRANDINGS = [
     'Chrome',
@@ -44,6 +44,8 @@ ARCH_MAP = {
 ARCH_MAP = {
     'android': ['ia32', 'x64', 'arm-neon', 'arm64'],
     'linux': ['ia32', 'x64', 'noasm-x64', 'arm', 'arm-neon', 'arm64'],
+    'openbsd': ['x64', 'arm64', 'ia32'],
+    'freebsd': ['x64', 'arm64', 'ia32'],
     'mac': ['x64', 'arm64'],
     'win': ['ia32', 'x64', 'arm64'],
 }
@@ -123,7 +125,7 @@ def GetDsoName(target_os, dso_name, dso_version):
 
 
 def GetDsoName(target_os, dso_name, dso_version):
-    if target_os in ('linux', 'linux-noasm', 'android'):
+    if target_os in ('linux', 'linux-noasm', 'android', 'openbsd', 'freebsd'):
         return 'lib%s.so.%s' % (dso_name, dso_version)
     elif target_os == 'mac':
         return 'lib%s.%s.dylib' % (dso_name, dso_version)
@@ -476,7 +478,7 @@ def BuildFFmpeg(target_os, target_arch, host_os, host_
     # removing <sys/sysctl.h> soon, so this is needed to silence a deprecation
     # #warning which will be converted to an error via -Werror.
     # There is also no prctl.h
-    if target_os in ['linux', 'linux-noasm']:
+    if target_os in ['linux', 'linux-noasm', 'openbsd', 'freebsd']:
         pre_make_rewrites += [
             (r'(#define HAVE_SYSCTL [01])',
              r'#define HAVE_SYSCTL 0 /* \1 -- forced to 0 for Fuchsia */'),
@@ -599,7 +601,7 @@ def main(argv):
     configure_args = args[2:]
 
     if target_os not in ('android', 'linux', 'linux-noasm', 'mac', 'win',
-                         'all'):
+                         'all', 'openbsd', 'freebsd'):
         parser.print_help()
         return 1
 
@@ -672,7 +674,6 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
         '--disable-securetransport',
         '--disable-faan',
         '--disable-alsa',
-        '--disable-iamf',
 
         # Disable automatically detected external libraries. This prevents
         # automatic inclusion of things like hardware decoders. Each roll should
@@ -713,7 +714,7 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
             '--optflags="-O2"',
         ])
 
-    if target_os in ('linux', 'linux-noasm', 'android'):
+    if target_os in ('linux', 'linux-noasm', 'android', 'openbsd', 'freebsd'):
         if target_arch == 'x64':
             if target_os == 'android':
                 configure_flags['Common'].extend([
@@ -828,9 +829,6 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
 
                 configure_flags['Common'].extend([
                     '--target-os=linux',
-                    '--sysroot=' +
-                    os.path.join(CHROMIUM_ROOT_DIR,
-                                 'build/linux/debian_bullseye_arm64-sysroot'),
                     # See crbug.com/1467681. These could be removed eventually
                     '--disable-dotprod',
                     '--disable-i8mm',
@@ -1034,7 +1032,7 @@ def ConfigureAndBuild(target_arch, target_os, host_os,
             'Chrome', configure_flags['Common'] +
             configure_flags['ChromeAndroid'] + configure_args)
 
-    if target_os in ['linux', 'linux-noasm']:
+    if target_os in ['linux', 'linux-noasm', 'openbsd', 'freebsd']:
         # ChromeOS enables MPEG4 which requires error resilience :(
         chrome_os_flags = (configure_flags['Common'] +
                            configure_flags['Chrome'] +
