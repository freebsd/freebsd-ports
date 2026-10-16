Description: Set __version__ unconditionally. project.py no longer defines
  author or date, so the combined import from .project raised ImportError
  after binding version but before __version__ was assigned; the error was
  swallowed and postgresql.bin.pg_dotconf failed with "cannot import name
  '__version__' from 'postgresql'". Import only what project.py provides
  and drop the never-defined __author__/__date__ from __all__, which also
  fixes "from postgresql import *".
Issue ID: https://github.com/python-postgres/fe/pull/130
Changeset: none

--- postgresql/__init__.py.orig	2018-06-09 07:11:10 UTC
+++ postgresql/__init__.py
@@ -10,8 +10,6 @@ See <http://postgresql.org> for more inf
 for information about Python.
 """
 __all__ = [
-	'__author__',
-	'__date__',
 	'__version__',
 	'__docformat__',
 	'version',
@@ -27,11 +25,10 @@ version_info = () # overridden by subseq
 
 # Optional.
 try:
-	from .project import version_info, version, \
-		author as __author__, date as __date__
-	__version__ = version
+	from .project import version_info, version
 except ImportError:
 	pass
+__version__ = version
 
 # Avoid importing these until requested.
 _pg_iri = _pg_driver = _pg_param = None
