--- src/vs/code/electron-main/app.ts.orig	2020-05-05 21:48:19 UTC
+++ src/vs/code/electron-main/app.ts
@@ -446,7 +446,7 @@ export class CodeApplication extends Disposable {
 				services.set(IUpdateService, new SyncDescriptor(Win32UpdateService));
 				break;
 
-			case 'linux':
+			case 'linux': case 'freebsd':
 				if (process.env.SNAP && process.env.SNAP_REVISION) {
 					services.set(IUpdateService, new SyncDescriptor(SnapUpdateService, [process.env.SNAP, process.env.SNAP_REVISION]));
 				} else {
