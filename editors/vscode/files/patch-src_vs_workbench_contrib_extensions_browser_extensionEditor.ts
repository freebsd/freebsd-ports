--- src/vs/workbench/contrib/extensions/browser/extensionEditor.ts.orig	2020-04-16 15:59:11 UTC
+++ src/vs/workbench/contrib/extensions/browser/extensionEditor.ts
@@ -1390,7 +1390,8 @@ export class ExtensionEditor extends BaseEditor {
 
 		switch (platform) {
 			case 'win32': key = rawKeyBinding.win; break;
-			case 'linux': key = rawKeyBinding.linux; break;
+			case 'linux': case 'freebsd':
+				key = rawKeyBinding.linux; break;
 			case 'darwin': key = rawKeyBinding.mac; break;
 		}
 
