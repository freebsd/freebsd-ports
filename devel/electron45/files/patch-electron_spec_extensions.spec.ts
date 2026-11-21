--- electron/spec/extensions.spec.ts.orig	2026-11-18 23:46:22 UTC
+++ electron/spec/extensions.spec.ts
@@ -113,7 +113,7 @@ describe('chrome extensions', { retry: 0 }, () => {
   // On Linux, using this API scans mounted devices. A device with no identifying
   // udev properties, as seen on CI, fails DCHECK(!unique_id.empty()) in
   // storage_monitor::StorageInfo::MakeDeviceId().
-  ifdescribe(process.platform !== 'linux')('chrome.system.storage', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('chrome.system.storage', () => {
     let w: BrowserWindow;
 
     beforeEach(async () => {
