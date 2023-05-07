--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2023-05-03 19:37:04 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1733,7 +1733,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
