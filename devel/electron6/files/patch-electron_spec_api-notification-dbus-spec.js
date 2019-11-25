--- electron/spec/api-notification-dbus-spec.js.orig	2019-09-11 17:30:11 UTC
+++ electron/spec/api-notification-dbus-spec.js
@@ -14,6 +14,7 @@ const { remote } = require('electron')
 const { app } = remote
 
 const skip = process.platform !== 'linux' ||
+             process.platform !== 'freebsd' ||
              process.arch === 'ia32' ||
              process.arch.indexOf('arm') === 0 ||
              !process.env.DBUS_SESSION_BUS_ADDRESS;
