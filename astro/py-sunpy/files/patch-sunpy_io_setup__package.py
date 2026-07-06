--- sunpy/io/setup_package.py.orig	2026-07-03 08:33:41 UTC
+++ sunpy/io/setup_package.py
@@ -12,7 +12,7 @@ def get_extensions():
         return []
     cfg = defaultdict(list)
     cfg["include_dirs"].append(numpy.get_include())
-    cfg["sources"].extend(list((Path(__file__).parent / "src" / "ana").glob("*.c")))
+    cfg["sources"].extend([str(p) for p in (Path(__file__).parent / "src" / "ana").glob("*.c")])
     if get_compiler() == 'msvc':
         cfg["extra_compile_args"].extend([
             "/O2",
