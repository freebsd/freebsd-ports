--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2022-02-02 16:57:24 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1759,7 +1759,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
