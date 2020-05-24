--- electron/lib/common/api/clipboard.js.orig	2019-05-23 04:07:30 UTC
+++ electron/lib/common/api/clipboard.js
@@ -1,6 +1,6 @@
 'use strict'
 
-if (process.platform === 'linux' && process.type === 'renderer') {
+if ((process.platform === 'linux' || process.platform === 'freebsd') && process.type === 'renderer') {
   // On Linux we could not access clipboard in renderer process.
   const { getRemote } = require('@electron/internal/renderer/remote')
   module.exports = getRemote('clipboard')
