--- electron/spec/api-clipboard-spec.js.orig	2021-01-22 23:55:24 UTC
+++ electron/spec/api-clipboard-spec.js
@@ -35,7 +35,7 @@ describe('clipboard module', () => {
   describe('clipboard.readHTML()', () => {
     it('returns markup correctly', () => {
       const text = '<string>Hi</string>';
-      const markup = process.platform === 'darwin' ? "<meta charset='utf-8'><string>Hi</string>" : process.platform === 'linux' ? '<meta http-equiv="content-type" ' + 'content="text/html; charset=utf-8"><string>Hi</string>' : '<string>Hi</string>';
+      const markup = process.platform === 'darwin' ? "<meta charset='utf-8'><string>Hi</string>" : (process.platform === 'linux' || process.platform === 'freebsd') ? '<meta http-equiv="content-type" ' + 'content="text/html; charset=utf-8"><string>Hi</string>' : '<string>Hi</string>';
       clipboard.writeHTML(text);
       expect(clipboard.readHTML()).to.equal(markup);
     });
@@ -51,7 +51,7 @@ describe('clipboard module', () => {
 
   describe('clipboard.readBookmark', () => {
     before(function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         this.skip();
       }
     });
@@ -77,7 +77,7 @@ describe('clipboard module', () => {
       const rtf = '{\\rtf1\\utf8 text}';
       const p = path.join(fixtures, 'assets', 'logo.png');
       const i = nativeImage.createFromPath(p);
-      const markup = process.platform === 'darwin' ? "<meta charset='utf-8'><b>Hi</b>" : process.platform === 'linux' ? '<meta http-equiv="content-type" ' + 'content="text/html; charset=utf-8"><b>Hi</b>' : '<b>Hi</b>';
+      const markup = process.platform === 'darwin' ? "<meta charset='utf-8'><b>Hi</b>" : (process.platform === 'linux' || process.platform === 'freebsd') ? '<meta http-equiv="content-type" ' + 'content="text/html; charset=utf-8"><b>Hi</b>' : '<b>Hi</b>';
       const bookmark = { title: 'a title', url: 'test' };
       clipboard.write({
         text: 'test',
@@ -93,7 +93,7 @@ describe('clipboard module', () => {
       const readImage = clipboard.readImage();
       expect(readImage.toDataURL()).to.equal(i.toDataURL());
 
-      if (process.platform !== 'linux') {
+      if (process.platform !== 'linux' && process.platform !== 'freebsd') {
         expect(clipboard.readBookmark()).to.deep.equal(bookmark);
       }
     });
