
$FreeBSD$

--- IPython/parallel/__init__.py.orig
+++ IPython/parallel/__init__.py
@@ -25,8 +25,6 @@
     if zmq.__version__ < '2.1.7':
         raise ImportError("IPython.parallel requires pyzmq/0MQ >= 2.1.7 on Windows, "
         "and you appear to have %s"%zmq.__version__)
-elif zmq.__version__ < '2.1.4':
-    raise ImportError("IPython.parallel requires pyzmq/0MQ >= 2.1.4, you appear to have %s"%zmq.__version__)
 
 if zmq.zmq_version() >= '3.0.0':
     warnings.warn("""libzmq 3 detected.
