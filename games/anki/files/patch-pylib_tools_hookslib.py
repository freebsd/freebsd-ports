Skip code formatting with "ruff" on FreeBSD 15.0-CURRENT (observed with
n278368-5c9b1c7e5f27) to prevent following error:

[...]
FAILED: /wrkdirs/usr/ports/games/anki/work/anki-25.07.2/out/qt/_aqt/hooks.py
/wrkdirs/usr/ports/games/anki/work/anki-25.07.2/out/rust/release/runner run /wrkdirs/usr/ports/games/anki/work/anki-25.07.2/out/pyenv/bin/python qt/tools/genhooks_gui.py /wrkdirs/usr/ports/games/anki/work/anki-25.07.2/out/qt/_aqt/hooks.py
<jemalloc>: jemalloc_tsd.c:190: Failed assertion: "!tsd_in_nominal_list(tsd)"
Traceback (most recent call last):
      File "/wrkdirs/usr/ports/games/anki/work/anki-25.07.2/qt/tools/genhooks_gui.py", line 1381, in <module>
          write_file(path, hooks, prefix, suffix)
            File "/wrkdirs/usr/ports/games/anki/work/anki-25.07.2/pylib/tools/hookslib.py", line 208, in write_file
                subprocess.run([sys.executable, "-m", "ruff", "format", "-q", path], check=True)
                  File "/usr/local/lib/python3.11/subprocess.py", line 571, in run
                      raise CalledProcessError(retcode, process.args,
                                               subprocess.CalledProcessError: Command '['/wrkdirs/usr/ports/games/anki/work/anki-25.07.2/out/pyenv/bin/python', '-m', 'ruff', 'format', '-q', '/wrkdirs/usr/ports/games/anki/work/anki-25.07.2/out/qt/_aqt/hooks.py']' died with <Signals.SIGABRT: 6>.
                                               Failed with code Some(1): /wrkdirs/usr/ports/games/anki/work/anki-25.07.2/out/pyenv/bin/python qt/tools/genhooks_gui.py /wrkdirs/usr/ports/games/anki/work/anki-25.07.2/out/qt/_aqt/hooks.py
[...]

--- pylib/tools/hookslib.py.orig	2025-07-09 11:37:00 UTC
+++ pylib/tools/hookslib.py
@@ -7,6 +7,7 @@ from __future__ import annotations
 
 from __future__ import annotations
 
+import platform
 import subprocess
 import sys
 from dataclasses import dataclass
@@ -205,4 +206,6 @@ def write_file(path: str, hooks: list[Hook], prefix: s
 
     with open(path, "wb") as file:
         file.write(code.encode("utf8"))
-    subprocess.run([sys.executable, "-m", "ruff", "format", "-q", path], check=True)
+
+    if not (platform.system() == 'FreeBSD' and platform.release() == '15.0-CURRENT'):
+        subprocess.run([sys.executable, "-m", "ruff", "format", "-q", path], check=True)
