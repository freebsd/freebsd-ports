--- src/vs/code/electron-main/app.ts.orig	2026-08-11 22:14:08 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1167,6 +1167,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
