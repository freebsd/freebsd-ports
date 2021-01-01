--- ui/webui/resources/js/cr.js.orig	2019-03-15 06:38:29 UTC
+++ ui/webui/resources/js/cr.js
@@ -455,6 +455,11 @@ var cr = cr || function() {
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
