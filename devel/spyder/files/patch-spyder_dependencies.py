--- spyder/dependencies.py.orig	2022-11-04 20:45:25 UTC
+++ spyder/dependencies.py
@@ -53,15 +53,15 @@ PSUTIL_REQVER = '>=5.3'
 PYGMENTS_REQVER = '>=2.0'
 PYLINT_REQVER = '>=2.5.0;<3.0'
 PYLINT_VENV_REQVER = '>=2.1.1'
-PYLSP_REQVER = '>=1.6.0;<1.7.0'
+PYLSP_REQVER = '>0' # until dependency is updated
 PYLSP_BLACK_REQVER = '>=1.2.0'
 PYLS_SPYDER_REQVER = '>=0.4.0'
 PYXDG_REQVER = '>=0.26'
 PYZMQ_REQVER = '>=22.1.0'
-QDARKSTYLE_REQVER = '>=3.0.2;<3.1.0'
+QDARKSTYLE_REQVER = '>=3.0.2'
 QSTYLIZER_REQVER = '>=0.2.2'
-QTAWESOME_REQVER = '>=1.2.1'
-QTCONSOLE_REQVER = '>=5.4.0;<5.5.0'
+QTAWESOME_REQVER = '>0' # until dependency is updated
+QTCONSOLE_REQVER = '>0' # until dependency is updated
 QTPY_REQVER = '>=2.1.0'
 RTREE_REQVER = '>=0.9.7'
 SETUPTOOLS_REQVER = '>=49.6.0'
