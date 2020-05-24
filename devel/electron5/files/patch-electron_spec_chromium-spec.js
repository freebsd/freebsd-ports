--- electron/spec/chromium-spec.js.orig	2019-05-16 02:16:13 UTC
+++ electron/spec/chromium-spec.js
@@ -849,7 +849,7 @@ describe('chromium feature', () => {
     })
 
     it('can be get as context in canvas', () => {
-      if (process.platform === 'linux') {
+      if (process.platform === 'linux' || process.platform === 'freebsd') {
         // FIXME(alexeykuzmin): Skip the test.
         // this.skip()
         return
@@ -1533,12 +1533,13 @@ describe('font fallback', () => {
     expect(fonts[0].familyName).to.equal({
       'win32': 'Arial',
       'darwin': 'Helvetica',
-      'linux': 'DejaVu Sans' // I think this depends on the distro? We don't specify a default.
+      'linux': 'DejaVu Sans', // I think this depends on the distro? We don't specify a default.
+      'freebsd': 'DejaVu Sans'
     }[process.platform])
   })
 
   it('should fall back to Japanese font for sans-serif Japanese script', async function () {
-    if (process.platform === 'linux') {
+    if (process.platform === 'linux' || process.platform === 'freebsd') {
       return this.skip()
     }
     const html = `
