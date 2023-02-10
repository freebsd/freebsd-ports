--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2023-02-01 13:32:54 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1735,7 +1735,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
