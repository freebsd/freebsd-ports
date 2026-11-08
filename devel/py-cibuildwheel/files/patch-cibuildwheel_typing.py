-- Add "freebsd" to the PlatformName literal so the newly introduced FreeBSD
-- platform handling is consistent with the rest of the type annotations.

--- cibuildwheel/typing.py.orig	2026-09-14 15:11:41 UTC
+++ cibuildwheel/typing.py
@@ -12,7 +12,7 @@ PathOrStr = str | os.PathLike[str]
 PathOrStr = str | os.PathLike[str]


-PlatformName = Literal["linux", "macos", "windows", "pyodide", "android", "ios"]
+PlatformName = Literal["linux", "macos", "windows", "pyodide", "android", "ios", "freebsd"]
 PLATFORMS: Final[frozenset[PlatformName]] = frozenset(typing.get_args(PlatformName))


