--- node_modules/@vscode/os-proxy-resolver/index.js.orig	2026-07-24 12:34:17 UTC
+++ node_modules/@vscode/os-proxy-resolver/index.js
@@ -12,6 +12,8 @@ const packages = {
 	'linux-x64-musl': '@vscode/os-proxy-resolver-linux-x64-musl',
 	'win32-arm64': '@vscode/os-proxy-resolver-win32-arm64-msvc',
 	'win32-x64': '@vscode/os-proxy-resolver-win32-x64-msvc',
+	'freebsd-arm64': '@vscode/os-proxy-resolver-freebsd-arm64',
+	'freebsd-x64': '@vscode/os-proxy-resolver-freebsd-x64',
 };
 
 const platform = getPlatformPackage();
@@ -37,4 +39,4 @@ exports.resolveProxy = binding.resolveProxy;
 const binding = require(packageName);
 exports.ProxyResolver = binding.ProxyResolver;
 exports.resolveProxy = binding.resolveProxy;
-exports.readProxyConfig = binding.readProxyConfig;
\ No newline at end of file
+exports.readProxyConfig = binding.readProxyConfig;
