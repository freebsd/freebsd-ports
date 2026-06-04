--- src/vs/workbench/services/actions/common/menusExtensionPoint.ts.orig	2026-06-03 09:29:03 UTC
+++ src/vs/workbench/services/actions/common/menusExtensionPoint.ts
@@ -1272,7 +1272,10 @@ class CommandsTableRenderer extends Disposable impleme
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux':
+			case 'freebsd':
+				key = rawKeyBinding.linux;
+				break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
