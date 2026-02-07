- Add FreeBSD platform support for preferences handling

--- src/node/desktop/src/main/preferences/preferences.ts.orig	2025-11-30 10:22:28 UTC
+++ src/node/desktop/src/main/preferences/preferences.ts
@@ -57,6 +57,7 @@ switch (process.platform) {
     break;
   case 'win32':
   case 'linux':
+  case 'freebsd':
     legacyPreferenceManager = new FilePreferences();
     break;
   default:
