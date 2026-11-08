--- electron/spec/api-clipboard.spec.ts.orig	2026-10-16 03:32:58 UTC
+++ electron/spec/api-clipboard.spec.ts
@@ -54,7 +54,7 @@ ifdescribe(process.platform !== 'win32' || process.arc
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('clipboard.readBookmark', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('clipboard.readBookmark', () => {
     it('returns title and url', () => {
       clipboard.writeBookmark('a title', 'https://electronjs.org/');
 
@@ -73,7 +73,7 @@ ifdescribe(process.platform !== 'win32' || process.arc
   });
 
   describe('clipboard.read()', () => {
-    ifit(process.platform !== 'linux')('does not crash when reading various custom clipboard types', () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('does not crash when reading various custom clipboard types', () => {
       const type = process.platform === 'darwin' ? 'NSFilenamesPboardType' : 'FileNameW';
 
       expect(() => {
@@ -114,7 +114,7 @@ ifdescribe(process.platform !== 'win32' || process.arc
       const readImage = clipboard.readImage();
       expect(readImage.toDataURL()).toBe(i.toDataURL());
 
-      if (process.platform !== 'linux') {
+      if (process.platform !== 'linux' && process.platform !== 'freebsd') {
         if (process.platform !== 'win32') {
           expect(clipboard.readBookmark()).toEqual(bookmark);
         } else {
