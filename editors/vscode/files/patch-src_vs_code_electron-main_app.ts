--- src/vs/code/electron-main/app.ts.orig	2026-08-19 08:33:33 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1168,6 +1168,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
