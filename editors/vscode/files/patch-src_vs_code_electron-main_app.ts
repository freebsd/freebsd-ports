--- src/vs/code/electron-main/app.ts.orig	2020-07-21 14:27:11 UTC
+++ src/vs/code/electron-main/app.ts
@@ -427,7 +427,7 @@ export class CodeApplication extends Disposable {
 				services.set(IUpdateService, new SyncDescriptor(Win32UpdateService));
 				break;
 
-			case 'linux':
+			case 'linux': case 'freebsd':
 				if (process.env.SNAP && process.env.SNAP_REVISION) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env.SNAP, process.env.SNAP_REVISION]));
 				} else {
