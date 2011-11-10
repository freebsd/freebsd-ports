
$FreeBSD$

--- IPython/zmq/__init__.py.orig
+++ IPython/zmq/__init__.py
@@ -18,14 +18,6 @@
 except ImportError:
     raise ImportError("IPython.zmq requires pyzmq >= %s"%minimum_pyzmq_version)
 
-pyzmq_version = zmq.__version__
-
-if pyzmq_version < minimum_pyzmq_version:
-    raise ImportError("IPython.zmq requires pyzmq >= %s, but you have %s"%(
-                    minimum_pyzmq_version, pyzmq_version))
-
-del pyzmq_version
-
 if zmq.zmq_version() >= '3.0.0':
     warnings.warn("""libzmq 3 detected.
     It is unlikely that IPython's zmq code will work properly.
