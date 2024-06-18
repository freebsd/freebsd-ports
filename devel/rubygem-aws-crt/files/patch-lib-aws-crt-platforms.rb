--- lib/aws-crt/platforms.rb.orig	2024-06-15 18:32:30 UTC
+++ lib/aws-crt/platforms.rb
@@ -3,6 +3,7 @@ OS_BINARIES = {
 # Maps OS name to crt binary name.
 OS_BINARIES = {
   'darwin' => 'libaws-crt-ffi.dylib',
+  'freebsd' => 'libaws-crt-ffi.so',
   'linux' => 'libaws-crt-ffi.so',
   'mingw32' => 'aws-crt-ffi.dll'
 }.freeze
