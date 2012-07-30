--- ./setup.py.orig	2012-07-19 20:16:27.000000000 +1000
+++ ./setup.py	2012-07-19 20:16:36.000000000 +1000
@@ -44,7 +44,7 @@
         packages=['tox', ],
         entry_points={'console_scripts': 'tox=tox:cmdline'},
         install_requires=install_requires,
-        zip_safe=True,
+        zip_safe=False,
         classifiers=[
             'Development Status :: 5 - Production/Stable',
             'Intended Audience :: Developers',
@@ -60,4 +60,4 @@
     )
 
 if __name__ == '__main__':
-    main()
\ No newline at end of file
+    main()
