--- src/main-process/auto-update-manager.js.orig	2019-12-13 19:07:42 UTC
+++ src/main-process/auto-update-manager.js
@@ -101,7 +101,7 @@ module.exports = class AutoUpdateManager extends Event
           this.setState(UnsupportedState);
         }
         break;
-      case 'linux':
+      case 'linux': case 'freebsd':
         this.setState(UnsupportedState);
     }
   }
