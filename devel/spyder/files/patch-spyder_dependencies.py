--- spyder/dependencies.py.orig	2023-08-29 21:53:14 UTC
+++ spyder/dependencies.py
@@ -40,7 +40,7 @@ IPYTHON_REQVER = (
 INTERVALTREE_REQVER = None if is_pynsist() else '>=3.0.2'
 IPYTHON_REQVER = (
     ">=7.31.1,<9.0.0,!=8.8.0,!=8.9.0,!=8.10.0,!=8.11.0,!=8.12.0,!=8.12.1")
-JEDI_REQVER = '>=0.17.2,<0.19.0'
+JEDI_REQVER = '>=0.17.2'
 JELLYFISH_REQVER = '>=0.7'
 JSONSCHEMA_REQVER = '>=3.2.0'
 KEYRING_REQVER = '>=17.0.0'
@@ -54,7 +54,7 @@ PYLINT_VENV_REQVER = '>=3.0.2'
 PYGMENTS_REQVER = '>=2.0'
 PYLINT_REQVER = '>=2.5.0,<3.0'
 PYLINT_VENV_REQVER = '>=3.0.2'
-PYLSP_REQVER = '>=1.7.4,<1.8.0'
+PYLSP_REQVER = '>=1.7.4'
 PYLSP_BLACK_REQVER = '>=1.2.0,<3.0.0'
 PYLS_SPYDER_REQVER = '>=0.4.0'
 PYXDG_REQVER = '>=0.26'
