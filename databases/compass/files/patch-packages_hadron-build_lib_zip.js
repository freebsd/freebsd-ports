diff --git a/packages/hadron-build/lib/zip.js b/packages/hadron-build/lib/zip.js
index 0606edaff..2c247e675 100644
--- a/packages/hadron-build/lib/zip.js
+++ b/packages/hadron-build/lib/zip.js
@@ -8,6 +8,9 @@ var series = require('async').series;
 
 function zip(_opts, done) {
   var opts = Object.assign({}, _opts);
+  if (!opts.dir && !opts.out) {
+    return
+  }
   opts.dir = path.resolve(opts.dir);
   opts.out = path.resolve(opts.out);
   opts.platform = opts.platform || process.platform;
