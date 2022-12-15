--- electron/spec-main/api-native-image-spec.ts.orig	2021-01-22 23:55:24 UTC
+++ electron/spec-main/api-native-image-spec.ts
@@ -491,7 +491,7 @@ describe('nativeImage module', () => {
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('createThumbnailFromPath(path, size)', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('createThumbnailFromPath(path, size)', () => {
     it('throws when invalid size is passed', async () => {
       const badSize = { width: -1, height: -1 };
 
