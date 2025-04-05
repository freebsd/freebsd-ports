--- src/wheel/_bdist_wheel.py.orig	2024-08-04 14:54:33 UTC
+++ src/wheel/_bdist_wheel.py
@@ -54,8 +54,6 @@ def safe_version(version: str) -> str:
         return re.sub("[^A-Za-z0-9.]+", "-", version)
 
 
-setuptools_major_version = int(setuptools.__version__.split(".")[0])
-
 PY_LIMITED_API_PATTERN = r"cp3\d"
 
 
@@ -489,48 +487,8 @@ class bdist_wheel(Command):
 
     @property
     def license_paths(self) -> Iterable[str]:
-        if setuptools_major_version >= 57:
-            # Setuptools has resolved any patterns to actual file names
-            return self.distribution.metadata.license_files or ()
-
-        files: set[str] = set()
-        metadata = self.distribution.get_option_dict("metadata")
-        if setuptools_major_version >= 42:
-            # Setuptools recognizes the license_files option but does not do globbing
-            patterns = cast(Sequence[str], self.distribution.metadata.license_files)
-        else:
-            # Prior to those, wheel is entirely responsible for handling license files
-            if "license_files" in metadata:
-                patterns = metadata["license_files"][1].split()
-            else:
-                patterns = ()
-
-        if "license_file" in metadata:
-            warnings.warn(
-                'The "license_file" option is deprecated. Use "license_files" instead.',
-                DeprecationWarning,
-                stacklevel=2,
-            )
-            files.add(metadata["license_file"][1])
-
-        if not files and not patterns and not isinstance(patterns, list):
-            patterns = ("LICEN[CS]E*", "COPYING*", "NOTICE*", "AUTHORS*")
-
-        for pattern in patterns:
-            for path in iglob(pattern):
-                if path.endswith("~"):
-                    log.debug(
-                        f'ignoring license file "{path}" as it looks like a backup'
-                    )
-                    continue
-
-                if path not in files and os.path.isfile(path):
-                    log.info(
-                        f'adding license file "{path}" (matched pattern "{pattern}")'
-                    )
-                    files.add(path)
-
-        return files
+        # Setuptools has resolved any patterns to actual file names
+        return self.distribution.metadata.license_files or ()
 
     def egg2dist(self, egginfo_path: str, distinfo_path: str):
         """Convert an .egg-info directory into a .dist-info directory"""
