#!/usr/bin/env python
# To use:
#       python setup.py install
#

__version__ = "$FreeBSD: /tmp/pcvs/ports/lang/py-compiler/files/Attic/setup.py,v 1.1 2001-09-06 14:15:37 wjv Exp $"

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
libs = ["expat"]

setup(name = "pyexpat",
      description = "Interface to the Expat XML parser",
      
      ext_modules = [Extension("pyexpat", ["pyexpat.c"],
                               include_dirs = inc_dirs,
                               define_macros = [("HAVE_EXPAT_H", 1)],
                               libraries = libs,
                               library_dirs = lib_dirs)]
      )
