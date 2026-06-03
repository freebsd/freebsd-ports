--- src/vs/code/electron-main/app.ts.orig	2026-05-29 07:25:37 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1088,6 +1088,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
