--- src/vs/workbench/services/actions/common/menusExtensionPoint.ts.orig	2025-07-09 22:00:36 UTC
+++ src/vs/workbench/services/actions/common/menusExtensionPoint.ts
@@ -1174,7 +1174,10 @@ class CommandsTableRenderer extends Disposable impleme
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux':
+			case 'freebsd':
+				key = rawKeyBinding.linux;
+				break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
