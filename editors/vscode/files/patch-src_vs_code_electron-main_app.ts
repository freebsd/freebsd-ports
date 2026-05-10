--- src/vs/code/electron-main/app.ts.orig	2026-05-05 18:23:50 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1063,6 +1063,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
