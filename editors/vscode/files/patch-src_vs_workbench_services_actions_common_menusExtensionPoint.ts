--- src/vs/workbench/services/actions/common/menusExtensionPoint.ts.orig	2026-02-04 01:55:52 UTC
+++ src/vs/workbench/services/actions/common/menusExtensionPoint.ts
@@ -1216,7 +1216,10 @@ class CommandsTableRenderer extends Disposable impleme
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux':
+			case 'freebsd':
+				key = rawKeyBinding.linux;
+				break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
