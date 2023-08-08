===>  Configuring for py39-hypothesis-6.80.1
Traceback (most recent call last):
  File "<string>", line 1, in <module>
  File "setup.py", line 31, in <module>
    SOURCE = str(local_file("src"))
  File "setup.py", line 28, in local_file
    return Path(__file__).parent.joinpath(name).relative_to(Path.cwd())
  File "/usr/local/lib/python3.9/pathlib.py", line 939, in relative_to
    raise ValueError("{!r} is not in the subpath of {!r}"
ValueError: 'src' is not in the subpath of '/wrkdirs/usr/ports/devel/py-hypothesis/work-py39/hypothesis-6.80.1' OR one path is relative and the other is absolute.
*** Error code 1

--- setup.py.orig	2023-07-06 16:35:06 UTC
+++ setup.py
@@ -25,7 +25,7 @@ if sys.version_info[:2] < (3, 8):
 
 
 def local_file(name):
-    return Path(__file__).parent.joinpath(name).relative_to(Path.cwd())
+    return Path(__file__).resolve().parent.joinpath(name).relative_to(Path.cwd())
 
 
 SOURCE = str(local_file("src"))
