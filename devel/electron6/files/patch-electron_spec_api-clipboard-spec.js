--- electron/spec/api-clipboard-spec.js.orig	2019-09-11 17:30:11 UTC
+++ electron/spec/api-clipboard-spec.js
@@ -27,7 +27,7 @@ describe('clipboard module', () => {
   describe('clipboard.readHTML()', () => {
     it('returns markup correctly', () => {
       const text = '<string>Hi</string>'
-      const markup = process.platform === 'darwin' ? "<meta charset='utf-8'><string>Hi</string>" : process.platform === 'linux' ? '<meta http-equiv="content-type" ' + 'content="text/html; charset=utf-8"><string>Hi</string>' : '<string>Hi</string>'
+      const markup = process.platform === 'darwin' ? "<meta charset='utf-8'><string>Hi</string>" : (process.platform === 'linux' || process.platform === 'freebsd') ? '<meta http-equiv="content-type" ' + 'content="text/html; charset=utf-8"><string>Hi</string>' : '<string>Hi</string>'
       clipboard.writeHTML(text)
       expect(clipboard.readHTML()).to.equal(markup)
     })
@@ -43,7 +43,7 @@ describe('clipboard module', () => {
 
   describe('clipboard.readBookmark', () => {
     before(function () {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         this.skip()
       }
     })
@@ -69,7 +69,7 @@ describe('clipboard module', () => {
       const rtf = '{\\rtf1\\utf8 text}'
       const p = path.join(fixtures, 'assets', 'logo.png')
       const i = nativeImage.createFromPath(p)
-      const markup = process.platform === 'darwin' ? "<meta charset='utf-8'><b>Hi</b>" : process.platform === 'linux' ? '<meta http-equiv="content-type" ' + 'content="text/html; charset=utf-8"><b>Hi</b>' : '<b>Hi</b>'
+      const markup = process.platform === 'darwin' ? "<meta charset='utf-8'><b>Hi</b>" : (process.platform === 'linux' || process.platform === 'freebsd') ? '<meta http-equiv="content-type" ' + 'content="text/html; charset=utf-8"><b>Hi</b>' : '<b>Hi</b>'
       const bookmark = { title: 'a title', url: 'test' }
       clipboard.write({
         text: 'test',
@@ -84,7 +84,7 @@ describe('clipboard module', () => {
       expect(clipboard.readRTF()).to.equal(rtf)
       expect(clipboard.readImage().toDataURL()).to.equal(i.toDataURL())
 
-      if (process.platform !== 'linux') {
+      if (process.platform !== 'linux' && process.platform !== 'freebsd') {
         expect(clipboard.readBookmark()).to.deep.equal(bookmark)
       }
     })
