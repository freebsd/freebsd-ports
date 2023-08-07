--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2023-08-02 11:59:07 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1739,7 +1739,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
