-- Extend the minimal FreeBSD support so the unit tests can run on amd64.
-- Normalize the FreeBSD machine name "amd64" to "x86_64", include "freebsd"
-- in architecture tables/synonyms, and handle it in the 32-bit auto-arch path.
-- The host-platform detection for FreeBSD was already present in this file.

--- cibuildwheel/architecture.py.orig	2026-09-14 15:11:41 UTC
+++ cibuildwheel/architecture.py
@@ -26,12 +26,13 @@ PRETTY_NAMES: Final[dict[PlatformName, str]] = {
     "pyodide": "Pyodide",
     "android": "Android",
     "ios": "iOS",
+    "freebsd": "FreeBSD",
 }

 ARCH_SYNONYMS: Final[list[dict[PlatformName, str | None]]] = [
-    {"linux": "x86_64", "macos": "x86_64", "windows": "AMD64", "android": "x86_64"},
-    {"linux": "i686", "macos": None, "windows": "x86"},
-    {"linux": "aarch64", "macos": "arm64", "windows": "ARM64", "android": "arm64_v8a"},
+    {"linux": "x86_64", "macos": "x86_64", "windows": "AMD64", "android": "x86_64", "freebsd": "x86_64"},
+    {"linux": "i686", "macos": None, "windows": "x86", "freebsd": None},
+    {"linux": "aarch64", "macos": "arm64", "windows": "ARM64", "android": "arm64_v8a", "freebsd": "aarch64"},
 ]


@@ -133,6 +134,11 @@ class Architecture(StrEnum):
     @classmethod
     def native_arch(cls, platform: PlatformName) -> Self | None:
         native_machine = platform_module.machine()
+
+        # FreeBSD reports amd64 instead of x86_64; normalize so the enum lookup works.
+        if sys.platform.startswith("freebsd") and native_machine == "amd64":
+            native_machine = "x86_64"
+
         native_architecture = cls(native_machine)

         # Cross-platform support. Used for --print-build-identifiers or docker builds.
@@ -189,16 +195,18 @@ class Architecture(StrEnum):

     @classmethod
     def all_archs(cls, platform: PlatformName) -> set[Self]:
+        linux_archs = {
+            cls.x86_64,
+            cls.i686,
+            cls.aarch64,
+            cls.ppc64le,
+            cls.s390x,
+            cls.armv7l,
+            cls.riscv64,
+        }
         all_archs_map = {
-            "linux": {
-                cls.x86_64,
-                cls.i686,
-                cls.aarch64,
-                cls.ppc64le,
-                cls.s390x,
-                cls.armv7l,
-                cls.riscv64,
-            },
+            "linux": linux_archs,
+            "freebsd": linux_archs,
             "macos": {cls.x86_64, cls.arm64, cls.universal2},
             "windows": {cls.x86, cls.AMD64, cls.ARM64},
             "pyodide": {cls.wasm32},
@@ -233,7 +241,7 @@ class Architecture(StrEnum):
             case "32":
                 if native_arch in archs_map.values():
                     return {native_arch}
-                elif native_arch in archs_map and platform in {"linux", "windows"}:
+                elif native_arch in archs_map and platform in {"linux", "freebsd", "windows"}:
                     if native_arch == cls.aarch64 and not _check_aarch32_el0():
                         # If we're on aarch64, skip if we cannot build armv7l wheels.
                         return set()
