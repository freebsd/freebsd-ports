--- node_modules/symbols-view/lib/tag-generator.js.orig	2019-12-27 07:45:34 UTC
+++ node_modules/symbols-view/lib/tag-generator.js
@@ -79,7 +79,7 @@ export default class TagGenerator {
   generate() {
     let tags = {};
     const packageRoot = this.getPackageRoot();
-    const command = path.join(packageRoot, 'vendor', `ctags-${process.platform}`);
+    const command = 'ctags';
     const defaultCtagsFile = path.join(packageRoot, 'lib', 'ctags-config');
     const args = [`--options=${defaultCtagsFile}`, '--fields=+KS'];
 
