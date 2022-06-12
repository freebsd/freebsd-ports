--- src/vs/code/electron-main/app.ts.orig	2022-06-08 11:20:55 UTC
+++ src/vs/code/electron-main/app.ts
@@ -587,7 +587,7 @@ export class CodeApplication extends Disposable {
 				services.set(IUpdateService, new SyncDescriptor(Win32UpdateService));
 				break;
 
-			case 'linux':
+			case 'linux': case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
