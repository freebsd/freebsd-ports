--- swift-docc/build-script-helper.py.orig	2026-09-29 00:09:25 UTC
+++ swift-docc/build-script-helper.py
@@ -176,6 +176,9 @@ def get_swiftpm_options(action, args):
       # Library rpath for swift, dispatch, Foundation, etc. when installing
       '-Xlinker', '-rpath', '-Xlinker', '$ORIGIN/../lib/swift/freebsd',
     ]
+    # FIXME: This is a temporary workaround for FreeBSD, which avoids
+    # optimization issues with the Swift compiler.
+    swiftpm_args += ['-Xswiftc', '-Onone']
     if action == 'install':
       swiftpm_args += ['--disable-local-rpath']
   elif build_os.startswith('openbsd'):
