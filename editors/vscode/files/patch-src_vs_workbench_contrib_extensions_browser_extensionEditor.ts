--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2023-11-01 09:39:20 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1778,7 +1778,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
