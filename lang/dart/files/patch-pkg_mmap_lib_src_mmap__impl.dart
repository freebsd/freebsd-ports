package:mmap hard-codes Linux's MAP_ANONYMOUS (0x20); FreeBSD's is
0x1000 (series 0022). Fixes the heap snapshot tool.
FreeBSD-specific, not submitted upstream yet.
--- pkg/mmap/lib/src/mmap_impl.dart.orig	2026-09-29 08:00:52 UTC
+++ pkg/mmap/lib/src/mmap_impl.dart
@@ -7,6 +7,7 @@ import 'dart:ffi';
 // ignore_for_file: non_constant_identifier_names
 
 import 'dart:ffi';
+import 'dart:io';
 import 'dart:typed_data';
 
 import 'package:ffi/ffi.dart';
@@ -74,7 +75,9 @@ const int kMapPrivate = 2;
 const int kProtWrite = 2;
 const int kProtExec = 4;
 const int kMapPrivate = 2;
-const int kMapAnon = 0x20;
+// FreeBSD, which the VM treats as a Linux variant, uses a different value.
+final int kMapAnon =
+    Platform.operatingSystemVersion.startsWith('FreeBSD') ? 0x1000 : 0x20;
 const int kMapFailed = -1;
 
 //  #include <cstddef>
