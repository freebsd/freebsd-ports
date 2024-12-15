--- src/vs/workbench/services/actions/common/menusExtensionPoint.ts.orig	2024-12-10 22:22:47 UTC
+++ src/vs/workbench/services/actions/common/menusExtensionPoint.ts
@@ -1135,7 +1135,7 @@ class CommandsTableRenderer extends Disposable impleme
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd': key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
