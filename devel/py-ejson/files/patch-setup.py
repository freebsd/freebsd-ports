--- setup.py.orig	2013-11-13 15:40:51 UTC
+++ setup.py
@@ -69,7 +69,7 @@ if __name__ == '__main__':
         packages=find_packages(exclude=['*tests*']),
         install_requires=install_requires,
         dependency_links=dependency_links,
-        classifiers=(
+        classifiers=[
             'Development Status :: 4 - Beta',
             'Intended Audience :: Developers',
             'License :: OSI Approved :: GNU General Public License v3 or later (GPLv3+)',
@@ -78,5 +78,5 @@ if __name__ == '__main__':
             'Operating System :: POSIX',
             'Programming Language :: Python',
             'Programming Language :: Python :: 2.7',
-        )
+        ]
     )
