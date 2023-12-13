--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2023-12-06 10:36:56 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1801,7 +1801,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
