Define a local repository to use "devel/protobuf" from the Ports tree.

--- proto/protobuf.bzl.orig	2022-06-24 05:10:06 UTC
+++ proto/protobuf.bzl
@@ -16,6 +16,7 @@ alias(
         "@ankidesktop//platforms:macos_arm64": "@protoc_bin_macos//:bin/protoc",
         "@ankidesktop//platforms:macos_x86_64": "@protoc_bin_macos//:bin/protoc",
         "@ankidesktop//platforms:linux_x86_64": "@protoc_bin_linux_x86_64//:bin/protoc",
+        "@ankidesktop//platforms:freebsd_all": "@protoc_bin_freebsd//:bin/protoc",
         "@ankidesktop//platforms:linux_arm64": "@protoc_bin_linux_arm64//:bin/protoc"
     }),
     visibility = ["//visibility:public"]
@@ -67,6 +68,11 @@ def setup_protobuf_binary(name):
         ],
         sha256 = "828d2bdfe410e988cfc46462bcabd34ffdda8cc172867989ec647eadc55b03b5",
         build_file_content = """exports_files(["bin/protoc.exe"])""",
+    )
+
+    native.local_repository(
+        name = "protoc_bin_freebsd",
+        path = "%%_MY_LOCALREPO%%/protoc_bin_freebsd",
     )
 
     if not native.existing_rule(name):
