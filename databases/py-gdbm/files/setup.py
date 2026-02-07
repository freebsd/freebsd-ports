#!/usr/bin/env python

import sysconfig
from setuptools import setup, Extension

prefix = sysconfig.get_config_var('prefix')
inc_dirs = [sysconfig.get_path('include') + "/internal",
            prefix + "/include"]
lib_dirs = [prefix + "/lib"]
libs = ["gdbm"]
macros = [('Py_BUILD_CORE_MODULE', 1)]

setup(ext_modules = [Extension('_gdbm', ['_gdbmmodule.c'],
                               include_dirs = inc_dirs,
                               libraries = libs,
                               library_dirs = lib_dirs,
                               define_macros = macros)]
      )
