--- src/vs/code/electron-main/app.ts.orig	2026-11-24 10:26:34 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1244,6 +1244,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
