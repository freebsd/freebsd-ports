--- src/window-event-handler.js.orig	2019-10-21 17:33:40 UTC
+++ src/window-event-handler.js
@@ -44,7 +44,7 @@ module.exports = class WindowEventHandler {
       })
     );
 
-    if (['win32', 'linux'].includes(process.platform)) {
+    if (['win32', 'linux', 'freebsd'].includes(process.platform)) {
       this.subscriptions.add(
         this.atomEnvironment.commands.add(this.window, {
           'window:toggle-menu-bar': this.handleWindowToggleMenuBar
