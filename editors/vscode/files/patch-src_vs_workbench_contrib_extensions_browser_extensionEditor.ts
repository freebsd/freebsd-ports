--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2023-10-03 13:06:11 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1741,7 +1741,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
