diff --git a/scripts/check-docs-link.js b/scripts/check-docs-link.js
index ca8b6486b..c7b18dd6b 100644
--- a/scripts/check-docs-link.js
+++ b/scripts/check-docs-link.js
@@ -5,8 +5,6 @@ const fetch = require('make-fetch-happen');
 const { JSDOM } = require('jsdom');
 
 async function main() {
-  const { stdout } = childProcess.spawnSync('git', ['ls-files']);
-
   let links = [];
 
   const files = stdout
