--- tests/functional/qemu_test/__init__.py.orig	2025-11-25 22:22:39 UTC
+++ tests/functional/qemu_test/__init__.py
@@ -16,7 +16,7 @@ from .decorators import skipIfMissingCommands, skipIfN
 from .decorators import skipIfMissingCommands, skipIfNotMachine, \
     skipFlakyTest, skipUntrustedTest, skipBigDataTest, skipSlowTest, \
     skipIfMissingImports, skipIfOperatingSystem, skipLockedMemoryTest, \
-    skipIfMissingEnv
+    skipIfMissingEnv, skipIfInsideFreeBSDJail
 from .archive import archive_extract
 from .uncompress import uncompress
 from .gdb import GDB
