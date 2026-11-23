--- src/vs/workbench/services/actions/common/menusExtensionPoint.ts.orig	2026-11-17 02:46:11 UTC
+++ src/vs/workbench/services/actions/common/menusExtensionPoint.ts
@@ -1290,7 +1290,10 @@ class CommandsTableRenderer extends Disposable impleme
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux':
+			case 'freebsd':
+				key = rawKeyBinding.linux;
+				break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
