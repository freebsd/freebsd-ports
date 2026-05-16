--- src/vs/code/electron-main/app.ts.orig	2026-05-12 20:17:22 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1032,6 +1032,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
