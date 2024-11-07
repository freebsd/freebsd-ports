--- src/vs/workbench/services/actions/common/menusExtensionPoint.ts.orig	2024-11-05 12:20:16 UTC
+++ src/vs/workbench/services/actions/common/menusExtensionPoint.ts
@@ -1122,7 +1122,7 @@ class CommandsTableRenderer extends Disposable impleme
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd': key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
