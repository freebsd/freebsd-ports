--- setup.py.orig	2019-12-04 11:05:36 UTC
+++ setup.py
@@ -15,10 +15,11 @@
 #  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 
 import sys
+import io
 from NanoVNASaver.about import version
 
-if sys.version_info < (3, 7):
-    print("You need at least Python 3.7 for this application!")
+if sys.version_info < (3, 3):
+    print("You need at least Python 3.3 for this application!")
     if sys.version_info[0] < 3:
         print("try running with python3 {}".format(" ".join(sys.argv)))
     sys.exit(1)
@@ -30,7 +31,7 @@ except ImportError:
     print("Try installing them with pip install setuptools")
     sys.exit(1)
 
-with open("README.md", "r") as fh:
+with io.open("README.md", "r", encoding="utf-8") as fh:
     long_description = fh.read()
 
 setup(
@@ -48,10 +49,4 @@ setup(
             'NanoVNASaver = NanoVNASaver.__main__:main'
         ],
     },
-    install_requires=[
-        'pyserial',
-        'PyQt5',
-        'numpy',
-        'scipy'
-    ],
 )
