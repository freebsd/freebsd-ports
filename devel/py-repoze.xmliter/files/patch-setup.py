--- setup.py.orig	2014-09-21 15:40:44 UTC
+++ setup.py
@@ -43,7 +43,7 @@ setup(name='repoze.xmliter',
       author_email="repoze-dev@lists.repoze.org",
       url="http://www.repoze.org",
       license="BSD-derived (http://www.repoze.org/LICENSE.txt)",
-      packages=find_packages(),
+      packages = ['repoze', 'repoze.xmliter'],
       include_package_data=True,
       namespace_packages=['repoze'],
       zip_safe=False,
