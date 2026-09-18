--- src/vs/platform/agentHost/test/node/codex/codexProviderConfiguration.test.ts.orig	2026-09-17 12:28:44 UTC
+++ src/vs/platform/agentHost/test/node/codex/codexProviderConfiguration.test.ts
@@ -135,7 +135,7 @@ suite('CodexProviderConfiguration', () => {
 	}
 
 	test('rereads the user configuration on a version conflict', async () => {
-		const client = new TestConfigurationClient(() => userConfiguration({ personality: 'pragmatic' }, `version-${client.readCount}`), () => {
+		const client: TestConfigurationClient = new TestConfigurationClient(() => userConfiguration({ personality: 'pragmatic' }, `version-${client.readCount}`), () => {
 			if (client.writes.length === 1) {
 				throw new JsonRpcError(-32600, 'Changed concurrently', { config_write_error_code: 'configVersionConflict' });
 			}
@@ -145,7 +145,7 @@ suite('CodexProviderConfiguration', () => {
 	});
 
 	test('preserves an alias installed concurrently by another client', async () => {
-		const client = new TestConfigurationClient(() => userConfiguration(client.readCount === 1 ? {} : { model_providers: { 'vscode-proxy': portableProvider } }), () => {
+		const client: TestConfigurationClient = new TestConfigurationClient(() => userConfiguration(client.readCount === 1 ? {} : { model_providers: { 'vscode-proxy': portableProvider } }), () => {
 			throw new JsonRpcError(-32600, 'Changed concurrently', { config_write_error_code: 'configVersionConflict' });
 		});
 		await ensurePortableCodexProxyProvider(client);
@@ -153,7 +153,7 @@ suite('CodexProviderConfiguration', () => {
 	});
 
 	test('does not overwrite a conflicting alias introduced by a concurrent edit', async () => {
-		const client = new TestConfigurationClient(() => userConfiguration(client.readCount === 1 ? {} : { model_providers: { 'vscode-proxy': { name: 'User provider', env_key: 'CUSTOM_TOKEN' } } }), () => {
+		const client: TestConfigurationClient = new TestConfigurationClient(() => userConfiguration(client.readCount === 1 ? {} : { model_providers: { 'vscode-proxy': { name: 'User provider', env_key: 'CUSTOM_TOKEN' } } }), () => {
 			throw new JsonRpcError(-32600, 'Changed concurrently', { config_write_error_code: 'configVersionConflict' });
 		});
 		await assert.rejects(ensurePortableCodexProxyProvider(client), /already defines an incompatible/);
