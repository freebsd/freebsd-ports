--- src/unix/uim/uim.gyp.orig	2015-07-15 10:04:31.000000000 +0900
+++ src/unix/uim/uim.gyp	2016-05-11 00:37:33.495056000 +0900
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
