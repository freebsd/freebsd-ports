--- src/vs/workbench/services/actions/common/menusExtensionPoint.ts.orig	2025-06-11 13:47:56 UTC
+++ src/vs/workbench/services/actions/common/menusExtensionPoint.ts
@@ -1153,7 +1153,10 @@ class CommandsTableRenderer extends Disposable impleme
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux':
+			case 'freebsd':
+				key = rawKeyBinding.linux;
+				break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
