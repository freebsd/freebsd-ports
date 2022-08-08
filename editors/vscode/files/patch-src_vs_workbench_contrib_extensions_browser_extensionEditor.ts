--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2022-08-03 05:14:29 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1691,7 +1691,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
