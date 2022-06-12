--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2022-06-08 11:20:55 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1773,7 +1773,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
