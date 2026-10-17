--- buf/internal/toolchain.bzl.orig	2024-12-06 11:21:09.532761000 +0900
+++ buf/internal/toolchain.bzl	2024-12-06 11:22:08.244087000 +0900
@@ -148,44 +148,44 @@
         version = versions[0]["name"]
 
     os, cpu = _detect_host_platform(ctx)
-    if os not in ["linux", "darwin", "windows"] or cpu not in ["arm64", "amd64"]:
+    if os not in ["linux", "freebsd", "darwin", "windows"] or cpu not in ["arm64", "amd64"]:
         fail("Unsupported operating system or cpu architecture ")
     if os == "linux" and cpu == "arm64":
         cpu = "aarch64"
     if cpu == "amd64":
         cpu = "x86_64"
 
-    ctx.report_progress("Downloading buf release hash")
-    ctx.download(
-        url = [
-            "https://github.com/bufbuild/buf/releases/download/{}/sha256.txt".format(version),
-        ],
-        output = "sha256.txt",
-    )
+#    ctx.report_progress("Downloading buf release hash")
+#    ctx.download(
+#        url = [
+#            "https://github.com/bufbuild/buf/releases/download/{}/sha256.txt".format(version),
+#        ],
+#        output = "sha256.txt",
+#    )
     ctx.file("WORKSPACE", "workspace(name = \"{name}\")".format(name = ctx.name))
     ctx.file("toolchain.bzl", _TOOLCHAIN_FILE)
-    sha_list = ctx.read("sha256.txt").splitlines()
-    for sha_line in sha_list:
-        if sha_line.strip(" ").endswith(".tar.gz"):
-            continue
-        (sum, _, bin) = sha_line.partition(" ")
-        bin = bin.strip(" ")
-        lower_case_bin = bin.lower()
-        if lower_case_bin.find(os) == -1 or lower_case_bin.find(cpu) == -1:
-            continue
+#    sha_list = ctx.read("sha256.txt").splitlines()
+#    for sha_line in sha_list:
+#        if sha_line.strip(" ").endswith(".tar.gz"):
+#            continue
+#        (sum, _, bin) = sha_line.partition(" ")
+#        bin = bin.strip(" ")
+#        lower_case_bin = bin.lower()
+#        if lower_case_bin.find(os) == -1 or lower_case_bin.find(cpu) == -1:
+#            continue
 
-        output = lower_case_bin[:lower_case_bin.find(os) - 1]
-        if os == "windows":
-            output += ".exe"
+#        output = lower_case_bin[:lower_case_bin.find(os) - 1]
+#        if os == "windows":
+#            output += ".exe"
+#
+#        ctx.report_progress("Downloading " + bin)
+#        download_info = ctx.download(
+#            url = "https://github.com/bufbuild/buf/releases/download/{}/{}".format(version, bin),
+#            sha256 = sum,
+#            executable = True,
+#            output = output,
+#        )
 
-        ctx.report_progress("Downloading " + bin)
-        download_info = ctx.download(
-            url = "https://github.com/bufbuild/buf/releases/download/{}/{}".format(version, bin),
-            sha256 = sum,
-            executable = True,
-            output = output,
-        )
-
     if os == "darwin":
         os = "osx"
 
