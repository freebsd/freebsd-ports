--- electron/spec-main/api-native-image-spec.ts.orig	2023-01-24 08:00:52 UTC
+++ electron/spec-main/api-native-image-spec.ts
@@ -423,7 +423,7 @@ describe('nativeImage module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('createThumbnailFromPath(path, size)', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('createThumbnailFromPath(path, size)', () => {
     it('throws when invalid size is passed', async () => {
       const badSize = { width: -1, height: -1 };
 
