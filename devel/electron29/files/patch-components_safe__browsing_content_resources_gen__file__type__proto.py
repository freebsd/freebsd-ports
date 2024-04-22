--- components/safe_browsing/content/resources/gen_file_type_proto.py.orig	2023-02-01 18:43:17 UTC
+++ components/safe_browsing/content/resources/gen_file_type_proto.py
@@ -38,6 +38,8 @@ def PlatformTypes():
         "fuchsia":
         download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_FUCHSIA,
         "linux": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,
+        "openbsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,
+        "freebsd": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_LINUX,
         "mac": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_MAC,
         "win": download_file_types_pb2.DownloadFileType.PLATFORM_TYPE_WINDOWS,
     }
@@ -181,7 +183,7 @@ class DownloadFileTypeProtoGenerator(BinaryProtoGenera
             '-t',
             '--type',
             help='The platform type. One of android, chromeos, ' +
-            'linux, mac, win')
+            'linux, mac, win, openbsd, freebsd')
 
     def AddExtraCommandLineArgsForVirtualEnvRun(self, opts, command):
         if opts.type is not None:
