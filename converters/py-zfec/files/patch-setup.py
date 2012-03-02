--- setup.py.orig	2012-03-02 17:06:05.000000000 +0800
+++ setup.py	2012-03-02 17:06:28.000000000 +0800
@@ -161,7 +161,6 @@
       tests_require=tests_require,
       packages=find_packages(),
       include_package_data=True,
-      data_files=data_files,
       setup_requires=setup_requires,
       classifiers=trove_classifiers,
       entry_points = { 'console_scripts': [ 'zfec = %s.cmdline_zfec:main' % PKG, 'zunfec = %s.cmdline_zunfec:main' % PKG ] },
