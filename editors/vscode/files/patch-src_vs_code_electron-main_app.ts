--- src/vs/code/electron-main/app.ts.orig	2025-06-23 07:50:00 UTC
+++ src/vs/code/electron-main/app.ts
@@ -990,6 +990,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
