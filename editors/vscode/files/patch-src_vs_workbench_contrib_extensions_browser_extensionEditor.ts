--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2021-07-14 21:51:05 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1381,7 +1381,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
