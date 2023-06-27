--- electron/spec/api-clipboard-spec.ts.orig	2023-01-24 16:58:16 UTC
+++ electron/spec/api-clipboard-spec.ts
@@ -43,7 +43,7 @@ ifdescribe(process.platform !== 'win32' || process.arc
     });
   });
 
-  ifdescribe(process.platform !== 'linux')('clipboard.readBookmark', () => {
+  ifdescribe(process.platform !== 'linux' && process.platform !== 'freebsd')('clipboard.readBookmark', () => {
     it('returns title and url', () => {
       clipboard.writeBookmark('a title', 'https://electronjs.org');
 
@@ -62,7 +62,7 @@ ifdescribe(process.platform !== 'win32' || process.arc
   });
 
   describe('clipboard.read()', () => {
-    ifit(process.platform !== 'linux')('does not crash when reading various custom clipboard types', () => {
+    ifit(process.platform !== 'linux' && process.platform !== 'freebsd')('does not crash when reading various custom clipboard types', () => {
       const type = process.platform === 'darwin' ? 'NSFilenamesPboardType' : 'FileNameW';
 
       expect(() => {
@@ -99,7 +99,7 @@ ifdescribe(process.platform !== 'win32' || process.arc
       const readImage = clipboard.readImage();
       expect(readImage.toDataURL()).to.equal(i.toDataURL());
 
-      if (process.platform !== 'linux') {
+      if (process.platform !== 'linux' && process.platform !== 'freebsd') {
         if (process.platform !== 'win32') {
           expect(clipboard.readBookmark()).to.deep.equal(bookmark);
         } else {
