--- src/vs/code/electron-main/app.ts.orig	2026-07-22 14:55:04 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1152,6 +1152,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
