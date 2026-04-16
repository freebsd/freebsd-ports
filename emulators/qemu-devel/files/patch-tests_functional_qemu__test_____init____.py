--- tests/functional/qemu_test/__init__.py.orig	2026-01-30 13:52:59 UTC
+++ tests/functional/qemu_test/__init__.py
@@ -16,7 +16,7 @@ from .decorators import skipIfMissingCommands, skipIfN
 from .decorators import skipIfMissingCommands, skipIfNotMachine, \
     skipFlakyTest, skipUntrustedTest, skipBigDataTest, skipSlowTest, \
     skipIfMissingImports, skipIfOperatingSystem, skipUnlessOperatingSystem, \
-    skipLockedMemoryTest, skipIfMissingEnv
+    skipLockedMemoryTest, skipIfMissingEnv, skipIfInsideFreeBSDJail
 from .archive import archive_extract
 from .uncompress import uncompress
 from .gdb import GDB
