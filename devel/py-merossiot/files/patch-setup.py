--- setup.py.orig	2025-05-06 08:53:00 UTC
+++ setup.py
@@ -31,7 +31,6 @@ setup(
     long_description_content_type='text/markdown',
     keywords='meross smartplug smartbulb iot mqtt domotic switch MSL120 MSS110 MSS210 MSS310 MSS310h '
              'MSS425e MSS530H MSG100 MSH300 MS100 MSS710 MSXH0',
-    data_files=[('.', ['.version'])],
     project_urls={
         'Documentation': 'https://github.com/albertogeniola/MerossIot',
         'Funding': 'https://donate.pypi.org',
@@ -41,7 +40,7 @@ setup(
     install_requires=[
         'paho-mqtt>=2.1.0,<3.0.0',
         'requests>=2.19.1,<3.0.0',
-        'aiohttp[speedups]>=3.7.4.post0,<4.0.0',
+        'aiohttp>=3.7.4.post0,<4.0.0',
         'pycryptodomex>=3.20.0'
     ],
     python_requires='>=3.8',
