--- electron/spec/api-native-image.spec.ts.orig	2026-10-15 23:46:52 UTC
+++ electron/spec/api-native-image.spec.ts
@@ -511,7 +511,7 @@ describe('nativeImage module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('createThumbnailFromPath(path, size)', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('createThumbnailFromPath(path, size)', () => {
     useRemoteContext({ webPreferences: { contextIsolation: false, nodeIntegration: true } });
 
     it('throws when invalid size is passed', async () => {
