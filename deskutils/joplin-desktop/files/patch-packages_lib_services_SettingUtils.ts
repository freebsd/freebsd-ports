--- packages/lib/services/SettingUtils.ts.orig	2025-05-12 13:46:38 UTC
+++ packages/lib/services/SettingUtils.ts
@@ -37,7 +37,7 @@ export async function loadKeychainServiceAndSettings(k
 	// Using Linux with the keychain has been observed to cause all secure settings to be lost
 	// on Fedora 40 + GNOME. (This may have been related to running multiple Joplin instances).
 	// For now, make saving to the keychain opt-in until more feedback is received.
-	if (shim.isLinux() && !Setting.value('featureFlag.linuxKeychain')) {
+	if ((shim.isLinux() || shim.isFreeBSD()) && !Setting.value('featureFlag.linuxKeychain')) {
 		KeychainService.instance().readOnly = true;
 	}
 
