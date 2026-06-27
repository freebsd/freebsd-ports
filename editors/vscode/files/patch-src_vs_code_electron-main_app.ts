--- src/vs/code/electron-main/app.ts.orig	2026-06-23 01:46:13 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1092,6 +1092,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
