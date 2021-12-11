--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2021-12-06 21:35:50 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1743,7 +1743,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
