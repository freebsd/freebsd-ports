--- extensions/microsoft-authentication/esbuild.mts.orig	2026-03-12 12:52:55 UTC
+++ extensions/microsoft-authentication/esbuild.mts
@@ -21,6 +21,7 @@ switch (process.platform) {
 	case 'win32': platformFolder = 'windows'; break;
 	case 'darwin': platformFolder = 'macos'; break;
 	case 'linux': platformFolder = 'linux'; break;
+	case 'freebsd': platformFolder = 'freebsd'; break;
 	default: throw new Error(`Unsupported platform: ${process.platform}`);
 }
 
