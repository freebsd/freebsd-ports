--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2021-02-03 15:33:23 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1467,7 +1467,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
