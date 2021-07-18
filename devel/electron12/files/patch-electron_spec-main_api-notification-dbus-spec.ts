--- electron/spec-main/api-notification-dbus-spec.ts.orig	2021-01-22 23:55:24 UTC
+++ electron/spec-main/api-notification-dbus-spec.ts
@@ -12,7 +12,7 @@ import { app } from 'electron/main';
 import { ifdescribe } from './spec-helpers';
 import { promisify } from 'util';
 
-const skip = process.platform !== 'linux' ||
+const skip = (process.platform !== 'linux' && process.platform !== 'freebsd') ||
              process.arch === 'ia32' ||
              process.arch.indexOf('arm') === 0 ||
              !process.env.DBUS_SESSION_BUS_ADDRESS;
