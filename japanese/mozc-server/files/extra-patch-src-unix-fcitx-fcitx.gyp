--- src/unix/fcitx/fcitx.gyp.orig	2015-07-13 04:27:48.760816000 +0900
+++ src/unix/fcitx/fcitx.gyp	2015-07-13 04:30:04.604724000 +0900
@@ -44,7 +44,6 @@
         '../../client/client.gyp:client',
         '../../ipc/ipc.gyp:ipc',
         '../../session/session_base.gyp:ime_switch_util',
-        '../../session/session_base.gyp:session_protocol',
     ],
     'fcitx_defines': [
       'LOCALEDIR="<!@(fcitx4-config --prefix)/share/locale/"',
