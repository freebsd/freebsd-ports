--- src/vs/code/electron-main/app.ts.orig	2023-02-01 13:32:54 UTC
+++ src/vs/code/electron-main/app.ts
@@ -852,7 +852,7 @@ export class CodeApplication extends Disposable {
 				services.set(IUpdateService, new SyncDescriptor(Win32UpdateService));
 				break;
 
-			case 'linux':
+			case 'linux': case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
