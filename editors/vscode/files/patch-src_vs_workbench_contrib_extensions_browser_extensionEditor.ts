--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2023-02-28 11:07:20 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1732,7 +1732,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
