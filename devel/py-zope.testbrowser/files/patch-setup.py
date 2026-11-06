Description: Drop the zope.cachedescriptors requirement and the 'pytz > dev'
  pin.
Issue ID: none
Changeset: none
TODO: FreeBSD-specific (zope.cachedescriptors was removed from the ports
  tree), not for upstream.

--- setup.py.orig	2019-11-12 09:52:53 UTC
+++ setup.py
@@ -63,8 +63,7 @@ setup(
         'setuptools',
         'zope.interface',
         'zope.schema',
-        'zope.cachedescriptors',
-        'pytz > dev',
+        'pytz',
         'WebTest >= 2.0.30',
         'BeautifulSoup4',
         'SoupSieve >= 1.9.0',
