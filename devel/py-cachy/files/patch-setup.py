--- setup.py.orig	1970-01-01 00:00:00 UTC
+++ setup.py
@@ -5,16 +5,14 @@ packages = \
 ['cachy',
  'cachy.contracts',
  'cachy.serializers',
- 'cachy.stores',
- 'tests',
- 'tests.stores']
+ 'cachy.stores']
 
 package_data = \
 {'': ['*']}
 
 extras_require = \
 {'memcached': ['python-memcached>=1.59,<2.0'],
- 'msgpack': ['msgpack-python>=0.5,<0.6'],
+ 'msgpack': ['msgpack>=0.5'],
  'redis': ['redis>=3.3.6,<4.0.0']}
 
 setup_kwargs = {
