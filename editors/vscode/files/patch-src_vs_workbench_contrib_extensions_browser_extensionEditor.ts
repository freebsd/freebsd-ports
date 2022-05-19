--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2022-05-16 17:42:35 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1752,7 +1752,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
