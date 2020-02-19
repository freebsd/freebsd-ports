--- apm/node_modules/atom-package-manager/lib/install.js.orig	2019-12-27 05:57:00 UTC
+++ apm/node_modules/atom-package-manager/lib/install.js
@@ -159,7 +159,7 @@
           case 'win32':
             message += "\nYou can install Git by downloading, installing, and launching GitHub for Windows: https://windows.github.com\n";
             break;
-          case 'linux':
+          case 'linux': case 'freebsd':
             message += "\nYou can install Git from your OS package manager.\n";
         }
         message += "\nRun apm -v after installing Git to see what version has been detected.";
