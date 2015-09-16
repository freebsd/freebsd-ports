--- src/base/base.gyp.orig	2015-02-17 18:02:46.000000000 +0900
+++ src/base/base.gyp	2015-02-17 18:03:44.000000000 +0900
@@ -154,6 +154,16 @@
             'MOZC_SERVER_DIRECTORY="<(server_dir)"',
           ],
         }],
+        ['target_platform=="Linux" and tool_dir!=""', {
+          'defines': [
+            'MOZC_TOOL_DIRECTORY="<(tool_dir)"',
+          ],
+        }],
+        ['target_platform=="Linux" and renderer_dir!=""', {
+          'defines': [
+            'MOZC_RENDERER_DIRECTORY="<(renderer_dir)"',
+          ],
+        }],
         ['target_platform=="Linux" and document_dir!=""', {
           'defines': [
             'MOZC_DOCUMENT_DIRECTORY="<(document_dir)"',
