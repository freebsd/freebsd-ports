--- setup.py	2020-11-10 14:32:40.701965000 +0000
+++ setup.py	2020-11-10 14:53:04.048189000 +0000
@@ -2329,6 +2329,10 @@
 listed here, it may still be supported, if there's a C compiler for
 it. Ask around on comp.lang.python -- or just try compiling Python
 yourself.
+
+This implementation, Tauthon, is a backward-compatible fork of
+Python's 2.7.18 interpreter with new syntax, builtins, and libraries
+backported from Python 3.x.
 """
 
 CLASSIFIERS = """
@@ -2345,12 +2349,12 @@
     import warnings
     warnings.filterwarnings("ignore",category=DeprecationWarning)
     setup(# PyPI Metadata (PEP 301)
           name = "Python",
           version = sys.version.split()[0],
-          url = "http://www.python.org/%s" % sys.version[:3],
-          maintainer = "Guido van Rossum and the Python community",
-          maintainer_email = "python-dev@python.org",
+          url = "https://github.com/naftaliharris/tauthon",
+          maintainer = "Guido van Rossum, the Python community \
+and the Tauthon developers",
           description = "A high-level object-oriented programming language",
           long_description = SUMMARY.strip(),
           license = "PSF license",
           classifiers = filter(None, CLASSIFIERS.split("\n")),
