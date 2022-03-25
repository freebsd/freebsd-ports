--- setup.py.orig	2022-03-25 16:23:32 UTC
+++ setup.py
@@ -35,7 +35,7 @@ setup(name=__pkg_name__.replace("_", "-"),
       version=get_version(),
       url='https://github.com/nanoporetech/{}'.format(__pkg_name__),
       install_requires=installation_requirements,
-      packages=find_packages(),
+      packages=find_packages(exclude=['test']),
       package_data={__pkg_name__: ['vbz_plugin/*.so', 'vbz_plugin/*.dylib', 'vbz_plugin/*.dll']},
       python_requires='>=3.6',
       entry_points={'console_scripts': [
