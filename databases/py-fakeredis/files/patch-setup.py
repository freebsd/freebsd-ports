--- setup.py.orig	1970-01-01 00:00:00 UTC
+++ setup.py
@@ -8,10 +8,10 @@ package_data = \
 {'': ['*']}
 
 install_requires = \
-['redis<4.5', 'sortedcontainers>=2.4.0,<3.0.0']
+['redis<4.5', 'sortedcontainers>=2.3.0,<3.0.0']
 
 extras_require = \
-{'aioredis': ['aioredis>=2.0.1,<3.0.0'], 'lua': ['lupa>=1.13,<2.0']}
+{'aioredis': ['aioredis>=1.3.1,<3.0.0'], 'lua': ['lupa>=1.13,<2.0']}
 
 setup_kwargs = {
     'name': 'fakeredis',
