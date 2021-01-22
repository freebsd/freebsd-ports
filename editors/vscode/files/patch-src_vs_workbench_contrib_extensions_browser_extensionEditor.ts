--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2020-12-16 14:57:12 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1445,7 +1445,8 @@ export class ExtensionEditor extends EditorPane {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
