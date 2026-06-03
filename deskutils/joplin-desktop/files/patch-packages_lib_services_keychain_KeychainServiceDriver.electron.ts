--- packages/lib/services/keychain/KeychainServiceDriver.electron.ts.orig	2025-09-01 11:50:43 UTC
+++ packages/lib/services/keychain/KeychainServiceDriver.electron.ts
@@ -18,7 +18,7 @@ export default class KeychainServiceDriver extends Key
 	public constructor(appId: string, clientId: string) {
 		super(appId, clientId);
 
-		if (canUseSafeStorage() && shim.isLinux()) {
+		if (canUseSafeStorage() && (shim.isLinux() || shim.isFreeBSD())) {
 			logger.info('KeychainService Linux backend: ', shim.electronBridge()?.safeStorage?.getSelectedStorageBackend());
 		}
 	}
@@ -56,7 +56,7 @@ export default class KeychainServiceDriver extends Key
 					result = await shim.electronBridge().safeStorage.decryptString(data);
 				} catch (e) {
 					logger.warn('Decryption of a setting failed. Corrupted data or new keychain password? Error:', e);
-					if (shim.isLinux() && Setting.value('env') === 'dev') {
+					if ((shim.isLinux() || shim.isFreeBSD()) && Setting.value('env') === 'dev') {
 						logger.warn('If running Joplin in development mode with NodeJS installed from the Snap store, consider retrying with NodeJS installed from a different source.');
 					}
 				}
