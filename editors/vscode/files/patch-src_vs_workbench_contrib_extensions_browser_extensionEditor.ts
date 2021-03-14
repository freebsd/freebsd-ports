--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2021-03-04 22:21:59 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1478,7 +1478,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
