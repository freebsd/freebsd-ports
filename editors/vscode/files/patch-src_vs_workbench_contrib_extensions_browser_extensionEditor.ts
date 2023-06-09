--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2023-06-07 13:23:47 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1738,7 +1738,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
