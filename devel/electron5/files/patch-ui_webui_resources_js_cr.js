--- ui/webui/resources/js/cr.js.orig	2019-04-08 08:19:20 UTC
+++ ui/webui/resources/js/cr.js
@@ -463,6 +463,11 @@ var cr = cr || function(global) {
     get doc() {
       return document;
     },
+    
+    /** Whether this is on *BSD. */
+    get isBSD() {
+      return /BSD/.test(navigator.userAgent);
+    },
 
     /** Whether we are using a Mac or not. */
     get isMac() {
