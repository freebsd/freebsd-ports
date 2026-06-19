--- src/vs/code/electron-main/app.ts.orig	2026-06-15 22:24:03 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1091,6 +1091,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
