from distutils.core import setup, Extension
setup(name = "pqueue",
      ext_modules = [Extension('pqueue', ['pqueuemodule.c'])])
