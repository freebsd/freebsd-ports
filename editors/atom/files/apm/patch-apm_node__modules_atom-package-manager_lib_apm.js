--- apm/node_modules/atom-package-manager/lib/apm.js.orig	2019-12-27 05:56:26 UTC
+++ apm/node_modules/atom-package-manager/lib/apm.js
@@ -72,7 +72,7 @@
             }
             return callback(`${appLocation}/Contents/Resources/app.asar`);
           });
-        case 'linux':
+        case 'linux': case 'freebsd':
           appLocation = '/usr/local/share/atom/resources/app.asar';
           if (!fs.existsSync(appLocation)) {
             appLocation = '/usr/share/atom/resources/app.asar';
