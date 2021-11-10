#!/usr/bin/env python
# To use:
#       python setup.py install
#

import platform

try:
    import distutils
    from distutils import sysconfig
    from distutils.command.install import install
    from distutils.core import setup, Extension
except:
    raise SystemExit("Distutils problem")

install.sub_commands = [x for x in install.sub_commands if 'egg' not in x[0]]

prefix = sysconfig.PREFIX
inc_dirs = [prefix + "/include", "Modules/_sqlite"]
lib_dirs = [prefix + "/lib"]
libs = ["sqlite3"]
macros = [('MODULE_NAME', '"sqlite3"')]
sqlite_srcs = [
'_sqlite/connection.c',
'_sqlite/cursor.c',
'_sqlite/microprotocols.c',
'_sqlite/module.c',
'_sqlite/prepare_protocol.c',
'_sqlite/row.c',
'_sqlite/statement.c',
'_sqlite/util.c']

major, minor = map(int, platform.python_version_tuple()[:2])

if (major, minor) <= (3, 10):
    sqlite_srcs.append('_sqlite/cache.c',)

try:
    import ctypes
    ctypes.CDLL('libsqlite3.so').sqlite3_load_extension
except AttributeError:
    macros.append(('SQLITE_OMIT_LOAD_EXTENSION', '1'))

setup(name = "sqlite3",
      description = "SQLite 3 extension to Python",

      ext_modules = [Extension('_sqlite3', sqlite_srcs,
                               include_dirs = inc_dirs,
                               libraries = libs,
                               library_dirs = lib_dirs,
                               runtime_library_dirs = lib_dirs,
                               define_macros = macros)]
      )
