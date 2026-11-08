--- electron/spec/api-native-image.spec.ts.orig	2026-10-17 02:46:46 UTC
+++ electron/spec/api-native-image.spec.ts
@@ -569,7 +569,7 @@ describe('nativeImage module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('createThumbnailFromPath(path, size)', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('createThumbnailFromPath(path, size)', () => {
     useRemoteContext({ webPreferences: { contextIsolation: false, nodeIntegration: true } });
 
     it('throws when invalid size is passed', async () => {
