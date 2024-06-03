--- electron/spec/api-notification-dbus-spec.ts.orig	2023-10-20 08:29:17 UTC
+++ electron/spec/api-notification-dbus-spec.ts
@@ -12,7 +12,7 @@ import { app } from 'electron/main';
 import { ifdescribe } from './lib/spec-helpers';
 import { promisify } from 'node:util';
 
-const skip = process.platform !== 'linux' ||
+const skip = (process.platform !== 'linux' && process.platform !== 'freebsd') ||
              process.arch === 'ia32' ||
              process.arch.indexOf('arm') === 0 ||
              !process.env.DBUS_SESSION_BUS_ADDRESS;
