--- sourcekit-lsp/Utilities/build-script-helper.py.orig	2026-09-28 23:41:48 UTC
+++ sourcekit-lsp/Utilities/build-script-helper.py
@@ -144,6 +144,9 @@ def get_swiftpm_options(swift_exec: str, args: argpars
                          '-Xswiftc', '-I', '-Xswiftc', '/usr/local/include',
                          '-Xlinker', '-rpath', '-Xlinker', '$ORIGIN/../lib/swift/freebsd',
                          ]
+        # FIXME: This is a temporary workaround for FreeBSD, which avoids
+        # optimization issues with the Swift compiler.
+        swiftpm_args += ['-Xswiftc', '-Onone']
     elif build_os.startswith('openbsd'):
         swiftpm_args += [
             '-Xlinker', '-rpath', '-Xlinker', '$ORIGIN/../lib/swift/openbsd',
