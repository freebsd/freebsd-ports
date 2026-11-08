Description: Ignore the new class namespace attributes of Python 3.13 and 3.14
  (__static_attributes__, __firstlineno__, ...), which made every interface
  fail with InvalidInterface.
Issue ID: none
Changeset: https://github.com/zopefoundation/zope.interface/commit/0081260bd55c25847d8cf6aac929fc80f4f58fd3
  (__static_attributes__),
  https://github.com/zopefoundation/zope.interface/commit/adab2bd316b7a435d3d78871f31d43025421fb2b
  (__firstlineno__),
  https://github.com/zopefoundation/zope.interface/commit/682b65896b9ecacc6bf59aee96d1fcefc4018de5
  (__classdictcell__),
  https://github.com/zopefoundation/zope.interface/commit/8d269cb069c1f13ed59dbb0ef8f8ecc4cddb3069
  (__annotate_func__)
TODO: Drop when updating to zope.interface 8.2 or later (the first release
  with __annotate_func__, needed for Python 3.14).

--- src/zope/interface/interface.py.orig	2021-03-18 10:15:23 UTC
+++ src/zope/interface/interface.py
@@ -819,6 +819,16 @@ class InterfaceClass(_InterfaceClassBase
                 '__qualname__',
                 # __annotations__: PEP 3107 (Python 3.0+)
                 '__annotations__',
+                # __static_attributes__: Python 3.13a6+
+                # https://github.com/python/cpython/pull/115913
+                '__static_attributes__',
+                # __firstlineno__: Python 3.13b1+
+                # https://github.com/python/cpython/pull/118475
+                '__firstlineno__',
+                # __classdictcell__: Python 3.14
+                '__classdictcell__',
+                # __annotate_func__: Python 3.14b1+
+                '__annotate_func__',
             )
             and aval is not _decorator_non_return
         }
