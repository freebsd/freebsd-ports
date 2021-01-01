--- packages/welcome/lib/guide-view.js.orig	2019-12-27 05:12:53 UTC
+++ packages/welcome/lib/guide-view.js
@@ -380,7 +380,7 @@ export default class GuideView {
   getApplicationMenuName() {
     if (process.platform === 'darwin') {
       return 'Atom';
-    } else if (process.platform === 'linux') {
+    } else if (process.platform === 'linux' || process.platform === 'freebsd') {
       return 'Edit';
     } else {
       return 'File';
