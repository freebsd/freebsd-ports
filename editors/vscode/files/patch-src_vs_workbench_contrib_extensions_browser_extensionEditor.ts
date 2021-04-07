--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2021-03-30 12:04:46 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1542,7 +1542,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
