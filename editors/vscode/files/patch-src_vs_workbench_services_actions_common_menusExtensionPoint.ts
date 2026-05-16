--- src/vs/workbench/services/actions/common/menusExtensionPoint.ts.orig	2026-05-12 20:17:22 UTC
+++ src/vs/workbench/services/actions/common/menusExtensionPoint.ts
@@ -1265,7 +1265,10 @@ class CommandsTableRenderer extends Disposable impleme
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux':
+			case 'freebsd':
+				key = rawKeyBinding.linux;
+				break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
