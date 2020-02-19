--- node_modules/text-buffer/lib/text-buffer.js.orig	2019-12-27 06:41:17 UTC
+++ node_modules/text-buffer/lib/text-buffer.js
@@ -1925,7 +1925,7 @@ class TextBuffer {
       try {
         await this.buffer.save(destination, this.getEncoding())
       } catch (error) {
-        const canEscalate = process.platform === 'darwin' || process.platform === 'linux'
+        const canEscalate = process.platform === 'darwin' || process.platform === 'linux' || process.platform === 'freebsd'
         if (error.code === 'EACCES' && destination === filePath && canEscalate) {
           const fsAdmin = require('fs-admin')
           try {
