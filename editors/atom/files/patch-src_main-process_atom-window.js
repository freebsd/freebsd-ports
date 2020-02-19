--- src/main-process/atom-window.js.orig	2019-10-21 17:33:40 UTC
+++ src/main-process/atom-window.js
@@ -53,7 +53,7 @@ module.exports = class AtomWindow extends EventEmitter
 
     // Don't set icon on Windows so the exe's ico will be used as window and
     // taskbar's icon. See https://github.com/atom/atom/issues/4811 for more.
-    if (process.platform === 'linux') options.icon = ICON_PATH;
+    if (process.platform === 'linux' || process.platform === 'freebsd') options.icon = ICON_PATH;
     if (this.shouldAddCustomTitleBar()) options.titleBarStyle = 'hidden';
     if (this.shouldAddCustomInsetTitleBar())
       options.titleBarStyle = 'hiddenInset';
