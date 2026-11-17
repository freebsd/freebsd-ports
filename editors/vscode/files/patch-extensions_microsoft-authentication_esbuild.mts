--- extensions/microsoft-authentication/esbuild.mts.orig	2026-11-10 19:27:51 UTC
+++ extensions/microsoft-authentication/esbuild.mts
@@ -22,6 +22,7 @@ switch (process.platform) {
 	case 'win32': platformFolder = 'windows'; break;
 	case 'darwin': platformFolder = 'macos'; break;
 	case 'linux': platformFolder = 'linux'; break;
+	case 'freebsd': platformFolder = 'freebsd'; break;
 	default: throw new Error(`Unsupported platform: ${process.platform}`);
 }
 
