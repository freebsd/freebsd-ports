--- src/vs/workbench/services/actions/common/menusExtensionPoint.ts.orig	2025-08-06 20:09:28 UTC
+++ src/vs/workbench/services/actions/common/menusExtensionPoint.ts
@@ -1172,7 +1172,10 @@ class CommandsTableRenderer extends Disposable impleme
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux':
+			case 'freebsd':
+				key = rawKeyBinding.linux;
+				break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
