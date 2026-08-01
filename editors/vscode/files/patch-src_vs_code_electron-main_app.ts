--- src/vs/code/electron-main/app.ts.orig	2026-07-28 06:40:51 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1164,6 +1164,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
