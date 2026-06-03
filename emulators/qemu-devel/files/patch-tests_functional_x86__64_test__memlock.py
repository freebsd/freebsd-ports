--- tests/functional/x86_64/test_memlock.py.orig	2026-01-30 13:52:59 UTC
+++ tests/functional/x86_64/test_memlock.py
@@ -14,7 +14,7 @@ from qemu_test import QemuSystemTest
 from typing import Dict
 
 from qemu_test import QemuSystemTest
-from qemu_test import skipLockedMemoryTest, skipUnlessOperatingSystem
+from qemu_test import skipLockedMemoryTest, skipUnlessOperatingSystem, skipIfInsideFreeBSDJail
 
 
 STATUS_VALUE_PATTERN = re.compile(r'^(\w+):\s+(\d+) kB', re.MULTILINE)
@@ -22,6 +22,7 @@ STATUS_VALUE_PATTERN = re.compile(r'^(\w+):\s+(\d+) kB
 
 @skipUnlessOperatingSystem('Linux')
 @skipLockedMemoryTest(2_097_152)  # 2GB
+@skipIfInsideFreeBSDJail()
 class MemlockTest(QemuSystemTest):
     """
     Runs a guest with memlock options.
