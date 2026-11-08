Description: Use the SQLAlchemy 1.4+ names for DeclarativeMeta and the
  registry.
Issue ID: none
Changeset: none
TODO: Upstream is dead (no commits or releases since 2017-10); keep locally.

--- sqlalchemy_imageattach/migration.py.orig	2016-06-30 19:06:51 UTC
+++ sqlalchemy_imageattach/migration.py
@@ -2,7 +2,7 @@
 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
 """
-from sqlalchemy.ext.declarative.api import DeclarativeMeta
+from sqlalchemy.orm import DeclarativeMeta
 from sqlalchemy.orm.session import Session
 
 from .entity import Image
@@ -57,7 +57,7 @@ def migrate(session, declarative_base, s
                         repr(source))
     classes = set(
         cls
-        for cls in declarative_base._decl_class_registry.values()
+        for cls in declarative_base.registry._class_registry.values()
         if isinstance(cls, type) and issubclass(cls, Image)
     )
 
