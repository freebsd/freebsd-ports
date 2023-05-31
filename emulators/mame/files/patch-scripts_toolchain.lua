--- scripts/toolchain.lua.orig	2023-05-27 02:18:45 UTC
+++ scripts/toolchain.lua
@@ -60,7 +60,8 @@ function androidToolchainRoot()
 		local hostTags = {
 			windows = "windows-x86_64",
 			linux   = "linux-x86_64",
-			macosx  = "darwin-x86_64"
+			macosx  = "darwin-x86_64",
+			bsd     = "freebsd-x86_64"
 		}
 		android.toolchainRoot = (os.getenv("ANDROID_NDK_HOME") or "") .. "/toolchains/llvm/prebuilt/" .. hostTags[os.get()]
 	end
