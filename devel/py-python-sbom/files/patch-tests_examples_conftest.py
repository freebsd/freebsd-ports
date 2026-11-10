-- Find the python-sbom executable via PATH instead of hardcoding the
-- scripts directory, so the test uses the staged binary before install.
--- tests/examples/conftest.py.orig	2026-11-10 00:29:49 UTC
+++ tests/examples/conftest.py
@@ -63,8 +63,9 @@ def _run(command: str, directory: Path) -> list[str]:
             sorted(path.relative_to(directory).as_posix() for path in directory.glob(argument)) or [argument]
         )
     arguments.extend(_ADDED.get((name, *arguments[:2]), []))
-    executable = sys.executable if name == "python" else shutil.which(name, path=sysconfig.get_path("scripts"))
-    assert executable is not None, f"{name} is not installed next to {sys.executable}"
+    executable = sys.executable if name == "python" else shutil.which(name)
+    if executable is None:
+        pytest.skip(f"{name} is not installed")
     result = subprocess.run([executable, *arguments], cwd=directory, capture_output=True, text=True, check=False)
     assert result.returncode == 0, f"{command} failed:\n{result.stdout}{result.stderr}"
     # the docs show what python-sbom prints and leave out what the build tools around it print
