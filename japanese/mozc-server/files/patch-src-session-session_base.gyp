--- src/session/session_base.gyp.orig	2015-09-09 23:49:24.267933000 +0900
+++ src/session/session_base.gyp	2015-09-09 23:50:12.347558000 +0900
@@ -101,6 +101,7 @@
         '../composer/composer.gyp:key_event_util',
         '../composer/composer.gyp:key_parser',
         '../config/config.gyp:config_handler',
+        '../protocol/protocol.gyp:commands_proto',
         '../protocol/protocol.gyp:config_proto',
         'keymap',
       ],
