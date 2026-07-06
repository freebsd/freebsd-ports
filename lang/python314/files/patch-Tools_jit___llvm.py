--- Tools/jit/_llvm.py.orig	2025-10-07 09:34:52 UTC
+++ Tools/jit/_llvm.py
@@ -71,25 +71,7 @@ async def _find_tool(tool: str, *, echo: bool = False)
 async def _find_tool(tool: str, *, echo: bool = False) -> str | None:
     # Unversioned executables:
     path = tool
-    if await _check_tool_version(path, echo=echo):
-        return path
-    # Versioned executables:
-    path = f"{tool}-{_LLVM_VERSION}"
-    if await _check_tool_version(path, echo=echo):
-        return path
-    # PCbuild externals:
-    externals = os.environ.get("EXTERNALS_DIR", _targets.EXTERNALS)
-    path = os.path.join(externals, _EXTERNALS_LLVM_TAG, "bin", tool)
-    if await _check_tool_version(path, echo=echo):
-        return path
-    # Homebrew-installed executables:
-    prefix = await _get_brew_llvm_prefix(echo=echo)
-    if prefix is not None:
-        path = os.path.join(prefix, "bin", tool)
-        if await _check_tool_version(path, echo=echo):
-            return path
-    # Nothing found:
-    return None
+    return path
 
 
 async def maybe_run(
@@ -104,5 +86,5 @@ async def run(tool: str, args: typing.Iterable[str], e
     """Run an LLVM tool if it can be found. Otherwise, raise RuntimeError."""
     output = await maybe_run(tool, args, echo=echo)
     if output is None:
-        raise RuntimeError(f"Can't find {tool}-{_LLVM_VERSION}!")
+        raise RuntimeError(f"Can't find {tool}!")
     return output
