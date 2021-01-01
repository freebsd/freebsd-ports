--- electron/spec/api-notification-dbus-spec.js.orig	2019-12-17 00:40:10 UTC
+++ electron/spec/api-notification-dbus-spec.js
@@ -13,7 +13,7 @@ const Promise = require('bluebird')
 const { remote } = require('electron')
 const { app } = remote
 
-const skip = process.platform !== 'linux' ||
+const skip = process.platform !== 'linux' || process.platform !== 'freebsd' ||
              process.arch === 'ia32' ||
              process.arch.indexOf('arm') === 0 ||
              !process.env.DBUS_SESSION_BUS_ADDRESS;
