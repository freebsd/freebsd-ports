--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2021-11-16 15:42:03 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1578,7 +1578,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
