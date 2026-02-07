--- setup.py.orig	2016-02-07 08:48:26 UTC
+++ setup.py
@@ -36,14 +36,6 @@ release.write_versionfile()
 sys.path.pop(0)
 
 packages = ["pygraphviz", "pygraphviz.tests"]
-docdirbase = 'share/doc/pygraphviz-%s' % release.version
-data = [
-    (docdirbase, glob("*.txt")),
-    (os.path.join(docdirbase, 'examples'), glob("examples/*.py")),
-    (os.path.join(docdirbase, 'examples'), glob("examples/*.dat")),
-    (os.path.join(docdirbase, 'examples'), glob("examples/*.dat.gz")),
-]
-package_data = {'': ['*.txt'], }
 
 if __name__ == "__main__":
     define_macros = []
@@ -75,14 +67,11 @@ if __name__ == "__main__":
         download_url=release.download_url,
         classifiers=release.classifiers,
         packages=packages,
-        data_files=data,
         ext_modules=extension,
         cmdclass={
             'install': AddExtensionInstallCommand,
             'develop': AddExtensionDevelopCommand,
             },
-        package_data=package_data,
-        include_package_data = True,
         test_suite='nose.collector',
         tests_require=['nose>=0.10.1', 'doctest-ignore-unicode>=0.1.0',],
     )
