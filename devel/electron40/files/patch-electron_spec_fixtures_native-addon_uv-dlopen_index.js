--- electron/spec/fixtures/native-addon/uv-dlopen/index.js.orig	2024-10-09 13:53:06 UTC
+++ electron/spec/fixtures/native-addon/uv-dlopen/index.js
@@ -4,7 +4,7 @@ const lib = (() => {
 
 const lib = (() => {
   switch (process.platform) {
-    case 'linux':
+    case 'linux': case 'freebsd':
       return path.resolve(__dirname, 'build/Release/foo.so');
     case 'darwin':
       return path.resolve(__dirname, 'build/Release/foo.dylib');
