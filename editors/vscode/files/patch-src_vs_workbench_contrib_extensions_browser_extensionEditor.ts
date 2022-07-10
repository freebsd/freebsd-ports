--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2022-07-05 18:15:23 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1689,7 +1689,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
