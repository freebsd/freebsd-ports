--- src/vs/workbench/services/actions/common/menusExtensionPoint.ts.orig	2026-03-06 23:06:10 UTC
+++ src/vs/workbench/services/actions/common/menusExtensionPoint.ts
@@ -1228,7 +1228,10 @@ class CommandsTableRenderer extends Disposable impleme
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux':
+			case 'freebsd':
+				key = rawKeyBinding.linux;
+				break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
