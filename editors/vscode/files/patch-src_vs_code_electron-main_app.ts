--- src/vs/code/electron-main/app.ts.orig	2025-09-09 22:02:15 UTC
+++ src/vs/code/electron-main/app.ts
@@ -988,6 +988,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
