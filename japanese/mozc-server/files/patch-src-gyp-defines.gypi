--- src/gyp/defines.gypi.orig	2017-01-01 15:13:15.000000000 +0900
+++ src/gyp/defines.gypi	2017-01-02 01:25:19.028785000 +0900
@@ -71,6 +71,8 @@
     # use_libibus represents if ibus library is used or not.
     # This option is only for Linux.
     'use_libibus%': '0',
+
+    'use_fcitx%': '0',
   },
   'target_defaults': {
     'defines': [
