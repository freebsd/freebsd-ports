--- swift-driver/Utilities/build-script-helper.py.orig	2024-06-04 23:56:01 UTC
+++ swift-driver/Utilities/build-script-helper.py
@@ -108,6 +108,10 @@ def get_swiftpm_options(args):
         # Android and fail.
         '-Xswiftc', '-Xcc', '-Xswiftc', '-U_GNU_SOURCE',
       ]
+    elif build_os.startswith('freebsd'):
+      swiftpm_args += [
+        '-Xlinker', '-rpath', '-Xlinker', '$ORIGIN/../lib/swift/freebsd',
+      ]
     else:
       # Library rpath for swift, dispatch, Foundation, etc. when installing
       swiftpm_args += [
@@ -121,7 +125,7 @@ def install_binary(file, source_dir, install_dir, verb
 
 def install_binary(file, source_dir, install_dir, verbose):
   print('Installing %s into: %s' % (file, install_dir))
-  cmd = ['rsync', '-a', os.path.join(source_dir, file), install_dir]
+  cmd = ['install', '-p', os.path.join(source_dir, file), install_dir]
   if verbose:
     print(' '.join(cmd))
   subprocess.check_call(cmd)
