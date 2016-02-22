--- setup.py.orig	2015-11-05 16:01:31 UTC
+++ setup.py
@@ -20,14 +20,16 @@ about = {}
 with open('rauth/__about__.py') as f:
     exec(f.read(), about)
 
-if sys.argv[-1] == 'test':
-    status = os.system('make check')
-    status >>= 8
-    sys.exit(status)
-
 install_requires = ['requests>=1.2.3']
+
+tests_require = [
+    'nose',
+    'mock',
+    'pycrypto',
+]
+
 if sys.version_info[0] == 2 and sys.version_info[1] < 7:
-    install_requires.append('unittest2>=0.5.1')
+    tests_require = ['unittest2>=0.5.1']
 
 classifiers = ['Development Status :: 5 - Production/Stable',
                'Intended Audience :: Developers',
@@ -57,6 +59,8 @@ setup(name=about['__title__'],
       url='https://github.com/litl/rauth',
       packages=find_packages(),
       install_requires=install_requires,
+      tests_require=tests_require,
+      test_suite='nose.collector',
       license=about['__license__'],
       keywords='oauth oauth2 rauth requests',
       classifiers=classifiers,
