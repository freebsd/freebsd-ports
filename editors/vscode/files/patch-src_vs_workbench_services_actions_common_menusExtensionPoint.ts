--- src/vs/workbench/services/actions/common/menusExtensionPoint.ts.orig	2025-12-10 18:02:22 UTC
+++ src/vs/workbench/services/actions/common/menusExtensionPoint.ts
@@ -1203,7 +1203,10 @@ class CommandsTableRenderer extends Disposable impleme
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux':
+			case 'freebsd':
+				key = rawKeyBinding.linux;
+				break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
