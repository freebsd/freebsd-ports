--- electron/spec-main/api-notification-dbus-spec.ts.orig	2020-05-28 05:06:40 UTC
+++ electron/spec-main/api-notification-dbus-spec.ts
@@ -12,7 +12,7 @@ import { app } from 'electron';
 import { ifdescribe } from './spec-helpers';
 import { promisify } from 'util';
 
-const skip = process.platform !== 'linux' ||
+const skip = (process.platform !== 'linux' && process.platform !== 'freebsd') ||
              process.arch === 'ia32' ||
              process.arch.indexOf('arm') === 0 ||
              !process.env.DBUS_SESSION_BUS_ADDRESS;
