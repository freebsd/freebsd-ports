--- setup.py.orig	2020-12-08 10:10:33 UTC
+++ setup.py
@@ -98,6 +98,5 @@ if __name__ == '__main__':
       },
       zip_safe = True,
       test_suite = 'tests',
-      setup_requires = ['pytest-runner'],
       tests_require = dev_require,
   )
