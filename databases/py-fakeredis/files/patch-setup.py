--- setup.py.orig	2022-06-09 12:46:18 UTC
+++ setup.py
@@ -8,10 +8,10 @@ package_data = \
 {'': ['*']}
 
 install_requires = \
-['redis<4.4', 'six>=1.16.0,<2.0.0', 'sortedcontainers>=2.4.0,<3.0.0']
+['redis<4.4', 'six>=1.16.0,<2.0.0', 'sortedcontainers>=2.3.0,<3.0.0']
 
 extras_require = \
-{'aioredis': ['aioredis>=2.0.1,<3.0.0'], 'lua': ['lupa>=1.13,<2.0']}
+{'aioredis': ['aioredis>=1.3.1,<3.0.0'], 'lua': ['lupa>=1.13,<2.0']}
 
 setup_kwargs = {
     'name': 'fakeredis',
