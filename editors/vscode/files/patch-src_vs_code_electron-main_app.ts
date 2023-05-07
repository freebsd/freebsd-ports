--- src/vs/code/electron-main/app.ts.orig	2023-05-03 19:37:04 UTC
+++ src/vs/code/electron-main/app.ts
@@ -855,7 +855,7 @@ export class CodeApplication extends Disposable {
 				services.set(IUpdateService, new SyncDescriptor(Win32UpdateService));
 				break;
 
-			case 'linux':
+			case 'linux': case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
