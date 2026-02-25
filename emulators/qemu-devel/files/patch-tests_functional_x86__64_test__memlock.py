--- tests/functional/x86_64/test_memlock.py.orig	2025-11-25 22:22:39 UTC
+++ tests/functional/x86_64/test_memlock.py
@@ -14,13 +14,14 @@ from qemu_test import QemuSystemTest
 from typing import Dict
 
 from qemu_test import QemuSystemTest
-from qemu_test import skipLockedMemoryTest
+from qemu_test import skipLockedMemoryTest, skipIfInsideFreeBSDJail
 
 
 STATUS_VALUE_PATTERN = re.compile(r'^(\w+):\s+(\d+) kB', re.MULTILINE)
 
 
 @skipLockedMemoryTest(2_097_152)  # 2GB
+@skipIfInsideFreeBSDJail()
 class MemlockTest(QemuSystemTest):
     """
     Runs a guest with memlock options.
