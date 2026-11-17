--- src/vs/code/electron-main/app.ts.orig	2026-11-10 19:27:51 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1239,6 +1239,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
