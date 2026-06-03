#!/usr/bin/env python

import platform
import sysconfig
from setuptools import setup, Extension

prefix = sysconfig.get_config_var('prefix')
inc_dirs = [sysconfig.get_path('include') + "/internal",
            prefix + "/include"]
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

if (major, minor) >= (3, 11):
    sqlite_srcs.append('_sqlite/blob.c',)

try:
    import ctypes
    ctypes.CDLL('libsqlite3.so').sqlite3_load_extension
except AttributeError:
    macros.append(('SQLITE_OMIT_LOAD_EXTENSION', '1'))

setup(ext_modules = [Extension('_sqlite3', sqlite_srcs,
                               include_dirs = inc_dirs,
                               libraries = libs,
                               library_dirs = lib_dirs,
                               runtime_library_dirs = lib_dirs,
                               define_macros = macros)]
      )
