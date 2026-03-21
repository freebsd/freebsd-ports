--- src/vs/code/electron-main/app.ts.orig	2026-03-06 23:06:10 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1029,6 +1029,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
