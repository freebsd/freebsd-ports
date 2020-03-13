--- electron/spec/api-clipboard-spec.js.orig	2020-02-28 00:07:16 UTC
+++ electron/spec/api-clipboard-spec.js
@@ -34,7 +34,7 @@ describe('clipboard module', () => {
   describe('clipboard.readHTML()', () => {
     it('returns markup correctly', () => {
       const text = '<string>Hi</string>'
-      const markup = process.platform === 'darwin' ? "<meta charset='utf-8'><string>Hi</string>" : process.platform === 'linux' ? '<meta http-equiv="content-type" ' + 'content="text/html; charset=utf-8"><string>Hi</string>' : '<string>Hi</string>'
+      const markup = process.platform === 'darwin' ? "<meta charset='utf-8'><string>Hi</string>" : (process.platform === 'linux' || process.platform === 'freebsd') ? '<meta http-equiv="content-type" ' + 'content="text/html; charset=utf-8"><string>Hi</string>' : '<string>Hi</string>'
       clipboard.writeHTML(text)
       expect(clipboard.readHTML()).to.equal(markup)
     })
@@ -50,7 +50,7 @@ describe('clipboard module', () => {
 
   describe('clipboard.readBookmark', () => {
     before(function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         this.skip()
       }
     })
@@ -76,7 +76,7 @@ describe('clipboard module', () => {
       const rtf = '{\\rtf1\\utf8 text}'
       const p = path.join(fixtures, 'assets', 'logo.png')
       const i = nativeImage.createFromPath(p)
-      const markup = process.platform === 'darwin' ? "<meta charset='utf-8'><b>Hi</b>" : process.platform === 'linux' ? '<meta http-equiv="content-type" ' + 'content="text/html; charset=utf-8"><b>Hi</b>' : '<b>Hi</b>'
+      const markup = process.platform === 'darwin' ? "<meta charset='utf-8'><b>Hi</b>" : (process.platform === 'linux' || process.platform === 'freebsd') ? '<meta http-equiv="content-type" ' + 'content="text/html; charset=utf-8"><b>Hi</b>' : '<b>Hi</b>'
       const bookmark = { title: 'a title', url: 'test' }
       clipboard.write({
         text: 'test',
@@ -91,7 +91,7 @@ describe('clipboard module', () => {
       expect(clipboard.readRTF()).to.equal(rtf)
       expect(clipboard.readImage().toDataURL()).to.equal(i.toDataURL())
 
-      if (process.platform !== 'linux') {
+      if (process.platform !== 'linux' && process.platform !== 'freebsd') {
         expect(clipboard.readBookmark()).to.deep.equal(bookmark)
       }
     })
