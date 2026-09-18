--- src/vs/code/electron-main/app.ts.orig	2026-09-15 07:24:32 UTC
+++ src/vs/code/electron-main/app.ts
@@ -1178,6 +1178,7 @@ export class CodeApplication extends Disposable {
 				break;
 
 			case 'linux':
+			case 'freebsd':
 				if (isLinuxSnap) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env['SNAP'], process.env['SNAP_REVISION']]));
 				} else {
