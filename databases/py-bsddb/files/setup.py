#!/usr/bin/env python
# To use:
#       python setup.py install
#

__version__ = "$FreeBSD: /tmp/pcvs/ports/databases/py-bsddb/files/setup.py,v 1.1 2003-07-31 20:03:51 perky Exp $"

import os
try:
    import distutils
    from distutils import sysconfig
    from distutils.command.install import install
    from distutils.core import setup, Extension
except:
    raise SystemExit, "Distutils problem"

prefix = sysconfig.PREFIX
inc_dirs = [prefix + "/include"]
lib_dirs = [prefix + "/lib"]
libs = [os.environ['BSDDB_VERSION']]

setup(name = "_bsddb",
      description = "BSDDB Extension to Python",
      
      ext_modules = [Extension('_bsddb', ['_bsddb.c'],
                               include_dirs = inc_dirs,
                               libraries = libs,
                               library_dirs = lib_dirs)]
      )
