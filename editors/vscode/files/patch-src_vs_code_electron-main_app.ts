--- src/vs/code/electron-main/app.ts.orig	2023-12-06 10:36:56 UTC
+++ src/vs/code/electron-main/app.ts
@@ -989,7 +989,7 @@ export class CodeApplication extends Disposable {
 				services.set(IUpdateService, new SyncDescriptor(Win32UpdateService));
 				break;
 
-			case 'linux':
+			case 'linux': case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
