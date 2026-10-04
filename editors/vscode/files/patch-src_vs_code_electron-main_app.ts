--- src/vs/code/electron-main/app.ts.orig	2026-09-30 08:38:38 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1226,6 +1226,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
