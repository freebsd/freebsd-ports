--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2023-01-09 16:16:14 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1717,7 +1717,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
