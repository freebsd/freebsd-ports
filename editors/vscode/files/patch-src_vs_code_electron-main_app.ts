--- src/vs/code/electron-main/app.ts.orig	2026-06-30 11:53:00 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1090,6 +1090,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
