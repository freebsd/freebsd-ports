--- build/linux/unbundle/replace_gn_files.py.orig	2023-02-01 18:43:08 UTC
+++ build/linux/unbundle/replace_gn_files.py
@@ -54,6 +54,7 @@ REPLACEMENTS = {
   'libevent': 'third_party/libevent/BUILD.gn',
   'libjpeg': 'third_party/libjpeg.gni',
   'libpng': 'third_party/libpng/BUILD.gn',
+  'libusb': 'third_party/libusb/BUILD.gn',
   'libvpx': 'third_party/libvpx/BUILD.gn',
   'libwebp': 'third_party/libwebp/BUILD.gn',
   'libxml': 'third_party/libxml/BUILD.gn',
