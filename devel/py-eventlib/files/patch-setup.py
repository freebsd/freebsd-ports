--- setup.py.orig	2013-10-02 01:17:23 UTC
+++ setup.py
@@ -66,7 +66,7 @@ if __name__ == '__main__':
         author=u'Lincoln de Sousa',
         author_email=u'lincoln@yipit.com',
         url='https://github.com/Yipit/eventlib',
-        packages=filter(lambda n: not n.startswith('tests'), find_packages()),
+        packages=list(filter(lambda n: not n.startswith('tests'), find_packages())),
         install_requires=install_requires,
         dependency_links=dependency_links,
         entry_points={
