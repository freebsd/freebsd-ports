Description: Install only the odoo package.  find_namespace_packages()
  with no filter treats every directory of the source tree as a
  namespace package, so setup.py install also copied doc/, setup/ and
  the build/ tree itself into site-packages.
Issue ID: none
Changeset: none
TODO: none

--- setup.py.orig	2026-06-18 17:11:05 UTC
+++ setup.py
@@ -21,7 +21,7 @@ setup(
     classifiers=[c for c in classifiers.split('\n') if c],
     license=license,
     scripts=['setup/odoo'],
-    packages=find_namespace_packages(),
+    packages=find_namespace_packages(include=['odoo', 'odoo.*']),
     package_dir={'%s' % lib_name: 'odoo'},
     include_package_data=True,
     install_requires=[
