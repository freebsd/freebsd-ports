Remove dependency on devel/py-ruff used to format the generated hooks.py
file as it is not relevant in a packaging use case.

Obtained from:

https://gitlab.alpinelinux.org/alpine/aports/-/raw/3.23-stable/community/anki/strip-formatter-deps.patch

--- pylib/tools/hookslib.py.orig	2025-09-17 06:50:13 UTC
+++ pylib/tools/hookslib.py
@@ -205,4 +205,3 @@ def write_file(path: str, hooks: list[Hook], prefix: s
 
     with open(path, "wb") as file:
         file.write(code.encode("utf8"))
-    subprocess.run([sys.executable, "-m", "ruff", "format", "-q", path], check=True)
