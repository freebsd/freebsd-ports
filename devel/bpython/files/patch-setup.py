
$FreeBSD$

--- setup.py.orig
+++ setup.py
@@ -37,13 +37,8 @@
     url = "http://www.bpython-interpreter.org/",
     long_description = """bpython is a fancy interface to the Python
     interpreter for Unix-like operating systems.""",
-    install_requires = [
-        'pygments'
-    ],
     packages = ["bpython", "bpdb"],
     data_files = [
-        (os.path.join(man_dir, 'man1'), ['doc/bpython.1']),
-        (os.path.join(man_dir, 'man5'), ['doc/bpython-config.5']),
         ('share/applications', ['data/bpython.desktop'])
     ],
     package_data = {'bpython': ['logo.png']},
