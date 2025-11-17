--- src/vs/workbench/services/actions/common/menusExtensionPoint.ts.orig	2025-11-11 14:25:32 UTC
+++ src/vs/workbench/services/actions/common/menusExtensionPoint.ts
@@ -1191,7 +1191,10 @@ class CommandsTableRenderer extends Disposable impleme
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux':
+			case 'freebsd':
+				key = rawKeyBinding.linux;
+				break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
