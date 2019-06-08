--- setup.py.orig	2019-06-06 10:50:07 UTC
+++ setup.py
@@ -28,7 +28,6 @@ setup(name='robotframework-pabot',
             'Development Status :: 5 - Production/Stable',
             'Framework :: Robot Framework'
       ],
-      scripts=[os.path.join('scripts', 'pabot'),
-               os.path.join('scripts', 'pabot.bat')],
+      scripts=[os.path.join('scripts', 'pabot')],
       license='Apache License, Version 2.0',
       install_requires=['robotframework', 'robotremoteserver>=1.1'])
