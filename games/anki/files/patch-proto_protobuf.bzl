Define a local repository to use "devel/protobuf" from the Ports tree.

At the moment it is only exposed for the "amd64" architecture but it should be
possible to add more architectures here.

--- proto/protobuf.bzl.orig	2021-07-30 08:30:37 UTC
+++ proto/protobuf.bzl
@@ -15,6 +15,7 @@ alias(
         "@ankidesktop//platforms:windows_x86_64": "@protoc_bin_windows//:bin/protoc.exe",
         "@ankidesktop//platforms:macos_x86_64": "@protoc_bin_macos//:bin/protoc",
         "@ankidesktop//platforms:linux_x86_64": "@protoc_bin_linux_x86_64//:bin/protoc",
+        "@ankidesktop//platforms:freebsd_x86_64": "@protoc_bin_freebsd//:bin/protoc",
         "@ankidesktop//platforms:linux_arm64": "@protoc_bin_linux_arm64//:bin/protoc"
     }),
     visibility = ["//visibility:public"]
@@ -66,6 +67,11 @@ def setup_protobuf_binary(name):
         ],
         sha256 = "642554ed4dd2dba94e1afddcccdd7d832999cea309299cc5952f13db389894f8",
         build_file_content = """exports_files(["bin/protoc.exe"])""",
+    )
+
+    native.local_repository(
+        name = "protoc_bin_freebsd",
+        path = "%%_MY_LOCALREPO%%/protoc_bin_freebsd",
     )
 
     if not native.existing_rule(name):
