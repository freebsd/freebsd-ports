--- src/vs/code/electron-main/app.ts.orig	2026-11-17 02:46:11 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1242,6 +1242,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
