--- setup.py.orig	1970-01-01 00:00:00 UTC
+++ setup.py
@@ -14,7 +14,7 @@ package_data = \
 
 extras_require = \
 {'memcached': ['python-memcached>=1.59,<2.0'],
- 'msgpack': ['msgpack-python>=0.5,<0.6'],
+ 'msgpack': ['msgpack>=0.5,<1'],
  'redis': ['redis>=3.3.6,<4.0.0']}
 
 setup_kwargs = {
