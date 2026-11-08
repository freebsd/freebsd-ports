Description: Use the lowercase project name, so the wheel and its
  dist-info are named grammalecte_fr as the ports framework expects for
  USE_PYTHON=pep517 (setuptools 63 keeps the case of the name).  The
  normalized project name is unchanged.
Issue ID: none
Changeset: none
TODO: FreeBSD-specific (ports framework naming), not for upstream.

--- setup.py.orig	2025-12-15 18:10:50 UTC
+++ setup.py
@@ -15,7 +15,7 @@ from setuptools import setup, find_packa
 #     long_description = f.read()

 setup(
-    name='Grammalecte-fr',
+    name='grammalecte-fr',

     # Versions should comply with PEP440.  For a discussion on single-sourcing
     # the version across setup.py and the project code, see
