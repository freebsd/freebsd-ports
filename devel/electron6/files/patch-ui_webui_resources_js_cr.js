--- ui/webui/resources/js/cr.js.orig	2019-09-10 11:14:40 UTC
+++ ui/webui/resources/js/cr.js
@@ -425,6 +425,11 @@ var cr = cr || function(global) {
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
