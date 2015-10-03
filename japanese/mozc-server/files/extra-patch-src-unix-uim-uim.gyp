--- src/unix/uim/uim.gyp.orig	2014-10-27 02:24:13.000000000 +0900
+++ src/unix/uim/uim.gyp	2015-09-26 06:34:58.683557000 +0900
@@ -31,6 +31,7 @@
 {
   'variables': {
     'relative_dir': 'unix/uim',
+    'gen_out_dir': '<(SHARED_INTERMEDIATE_DIR)/<(relative_dir)',
     'pkg_config_libs': [
       'uim',
     ],
@@ -39,6 +40,8 @@
     'uim_dependencies': [
       '../../base/base.gyp:base',
       '../../client/client.gyp:client',
+      '../../ipc/ipc.gyp:ipc',
+      '../../session/session_base.gyp:ime_switch_util',
     ],
   },
   'targets': [
@@ -49,7 +52,8 @@
         'key_translator.cc',
       ],
       'dependencies': [
-        '../../session/session_base.gyp:session_protocol',
+      '../../protocol/protocol.gyp:commands_proto',
+      '../../session/session_base.gyp:ime_switch_util',
       ],
       'cflags': [
         '<!@(pkg-config --cflags <@(pkg_config_libs))',
