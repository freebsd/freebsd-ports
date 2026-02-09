--- src/vs/code/electron-main/app.ts.orig	2026-02-04 01:55:52 UTC
+++ src/vs/code/electron-main/app.ts
@@ -994,6 +994,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
