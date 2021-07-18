--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2021-05-04 21:42:00 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1395,7 +1395,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
