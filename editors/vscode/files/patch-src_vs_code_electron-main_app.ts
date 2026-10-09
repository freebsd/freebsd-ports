--- src/vs/code/electron-main/app.ts.orig	2026-10-06 08:15:52 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1227,6 +1227,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
