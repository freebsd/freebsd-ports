--- packages/turndown/node_modules/rollup/dist/native.js.orig	2023-12-27 06:30:30 UTC
+++ packages/turndown/node_modules/rollup/dist/native.js
@@ -18,6 +18,10 @@ const bindingsByPlatformAndArch = {
 		arm64: { base: 'linux-arm64-gnu', musl: 'linux-arm64-musl' },
 		x64: { base: 'linux-x64-gnu', musl: 'linux-x64-musl' }
 	},
+	freebsd: {
+		arm64: { base: 'freebsd-arm64' },
+		x64: { base: 'freebsd-x64' }
+	},
 	win32: {
 		arm64: { base: 'win32-arm64-msvc' },
 		ia32: { base: 'win32-ia32-msvc' },
