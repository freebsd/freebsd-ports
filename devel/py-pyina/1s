#!/usr/bin/env python
#
# Author: Mike McKerns (mmckerns @caltech and @uqfoundation)
# Copyright (c) 1997-2016 California Institute of Technology.
# Copyright (c) 2016-2021 The Uncertainty Quantification Foundation.
# License: 3-clause BSD.  The full license text is available at:
#  - https://github.com/uqfoundation/pyina/blob/master/LICENSE

import os
import sys
# drop support for older python
unsupported = None
if sys.version_info < (2, 7):
    unsupported = 'Versions of Python before 2.7 are not supported'
elif (3, 0) <= sys.version_info < (3, 6):
    unsupported = 'Versions of Python before 3.6 are not supported'
if unsupported:
    raise ValueError(unsupported)

# set version numbers
stable_version = '0.2.5'
target_version = '0.2.5'
is_release = stable_version == target_version

# check if easy_install is available
try:
#   import __force_distutils__ #XXX: uncomment to force use of distutills
    from setuptools import setup, dist
    has_setuptools = True
except ImportError:
    from distutils.core import setup
    has_setuptools = False

# generate version number
if os.path.exists('pyina/info.py'):
    # is a source distribution, so use existing version
    os.chdir('pyina')
    with open('info.py','r') as f:
        f.readline() # header
        this_version = f.readline().split()[-1].strip("'")
    os.chdir('..')
elif stable_version == target_version:
    # we are building a stable release
    this_version = target_version
else:
    # we are building a distribution
    this_version = target_version + '.dev0'
    if is_release:
      from datetime import date
      today = "".join(date.isoformat(date.today()).split('-'))
      this_version += "-" + today

# get the license info
with open('LICENSE') as file:
    license_text = file.read()

# generate the readme text
long_description = \
"""----------------------------------------------
pyina: MPI parallel map and cluster scheduling
----------------------------------------------

About Pyina
===========

The ``pyina`` package provides several basic tools to make MPI-based
parallel computing more accessable to the end user. The goal
of ``pyina`` is to allow the user to extend their own code to MPI-based
parallel computing with minimal refactoring.

The central element of ``pyina`` is the parallel map algorithm.
``pyina`` currently provides two strategies for executing the parallel-map,
where a strategy is the algorithm for distributing the work list of
jobs across the availble nodes.  These strategies can be used *"in-the-raw"*
(i.e. directly) to provide the map algorithm to a user's own mpi-aware code.
Further, in ``pyina.mpi`` ``pyina`` provides pipe and map implementations
(known as *"easy map"*) that hide the MPI internals from the user. With the
*"easy map"*, the user can launch their code in parallel batch mode -- using
standard python and without ever having to write a line of MPI code.

There are several ways that a user would typically launch their code in
parallel -- directly with ``mpirun`` or ``mpiexec``, or through the use of a
scheduler such as *torque* or *slurm*. ``pyina`` encapsulates several of these
*"launchers"*, and provides a common interface to the different methods of
launching a MPI job.

``pyina`` is part of ``pathos``, a python framework for heterogeneous computing.
``pyina`` is in active development, so any user feedback, bug reports, comments,
or suggestions are highly appreciated.  A list of issues is located at https://github.com/uqfoundation/pyina/issues, with a legacy list maintained at https://uqfoundation.github.io/project/pathos/query.


Major Features
==============

``pyina`` provides a highly configurable parallel map interface
to running MPI jobs, with:

    - a map interface that extends the python ``map`` standard
    - the ability to submit batch jobs to a selection of schedulers
    - the ability to customize node and process launch configurations
    - the ability to launch parallel MPI jobs with standard python
    - ease in selecting different strategies for processing a work list


Current Release
===============

This documentation is for version ``pyina-%(thisver)s``.

The latest released version of ``pyina`` is available at:

    https://pypi.org/project/pyina

``pyina`` is distributed under a 3-clause BSD license.

    >>> import pyina
    >>> pyina.license()


Development Version
===================

You can get the latest development version with all the shiny new features at:

    https://github.com/uqfoundation

If you have a new contribution, please submit a pull request.


Installation
============

``pyina`` is packaged to install from source, so you must
download the tarball, unzip, and run the installer::

    [download]
    $ tar -xvzf pyina-%(relver)s.tar.gz
    $ cd pyina-%(relver)s
    $ python setup py build
    $ python setup py install

You will be warned of any missing dependencies and/or settings after
you run the "build" step above. ``pyina`` depends on ``dill``, ``pox``, ``pathos``, and
``mpi4py``, so you should install them first. A version of MPI must also be
installed. Launchers in ``pyina`` that submit to a scheduler will throw errors
if the underlying scheduler is not available, however a scheduler is not
required for ``pyina`` to execute.

Alternately, ``pyina`` can be installed with ``pip`` or ``easy_install``::

    $ pip install pyina


Requirements
============

``pyina`` requires:

    - ``python``, **version == 2.7** or **version >= 3.6**, or ``pypy``
    - ``numpy``, **version >= 1.0**
    - ``mpi4py``, **version >= 1.3**
    - ``dill``, **version >= 0.3.4**
    - ``pox``, **version >= 0.3.0**
    - ``pathos``, **version >= 0.2.8**

Optional requirements:

    - ``setuptools``, **version >= 0.6**
    - ``mystic``, **version >= 0.3.7**


More Information
================

Probably the best way to get started is to look at the documentation at
http://pyina.rtfd.io. Also see ``pyina.examples`` and ``pyina.tests``
for a set of scripts that demonstrate the configuration and launching of
mpi-based parallel jobs using the *"easy map"* interface. Also see
``pyina.examples_other`` for a set of scripts that test the more raw
internals of ``pyina``. You can run the tests with ``python -m pyina.tests``.
A script is included for querying, setting up, and tearing down an MPI
environment, see ``python -m pyina`` for more information. The source code
is generally well documented, so further questions may be resolved by
inspecting the code itself. Please feel free to submit a ticket on github,
or ask a question on stackoverflow (**@Mike McKerns**).
If you would like to share how you use ``pyina`` in your work, please send
an email (to **mmckerns at uqfoundation dot org**).

Important classes and functions are found here:

    - ``pyina.mpi``           [the map API definition]
    - ``pyina.schedulers``    [all available schedulers] 
    - ``pyina.launchers``     [all available launchers] 

Mapping strategies are found here:

    - ``pyina.mpi_scatter``   [the scatter-gather strategy]
    - ``pyina.mpi_pool``      [the worker pool strategy]

``pyina`` also provides a convience script that helps navigate the
MPI environment. This script can be run from anywhere with::

    $ mpi_world

If may also be convienent to set a shell alias for the launch of 'raw'
mpi-python jobs. Set something like the following (for bash)::

    $ alias mpython1='mpiexec -np 1 `which python`'
    $ alias mpython2='mpiexec -np 2 `which python`'
    $ ...


Citation
========

If you use ``pyina`` to do research that leads to publication, we ask that you
acknowledge use of ``pyina`` by citing the following in your publication::

    M.M. McKerns, L. Strand, T. Sullivan, A. Fang, M.A.G. Aivazis,
    "Building a framework for predictive science", Proceedings of
    the 10th Python in Science Conference, 2011;
    http://arxiv.org/pdf/1202.1056

    Michael McKerns and Michael Aivazis,
    "pathos: a framework for heterogeneous computing", 2010- ;
    https://uqfoundation.github.io/project/pathos

Please see https://uqfoundation.github.io/project/pathos or
http://arxiv.org/pdf/1202.1056 for further information.

""" % {'relver' : stable_version, 'thisver' : this_version}

# write readme file
with open('README', 'w') as file:
    file.write(long_description)

# generate 'info' file contents
def write_info_py(filename='pyina/info.py'):
    contents = """# THIS FILE GENERATED FROM SETUP.PY
this_version = '%(this_version)s'
stable_version = '%(stable_version)s'
readme = '''%(long_description)s'''
license = '''%(license_text)s'''
"""
    with open(filename, 'w') as file:
        file.write(contents % {'this_version' : this_version,
                               'stable_version' : stable_version,
                               'long_description' : long_description,
                               'license_text' : license_text })
    return

# write info file
write_info_py()

# platform-specific instructions
sdkroot_set = False
from sys import platform
if platform[:3] == 'win':
    pass
else: #platform = linux or mac
     if platform[:6] == 'darwin':
         # mpi4py has difficulty building on a Mac
         # see special installation instructions here:
         # http://mpi4py.scipy.org/docs/usrman/install.html
         import os
         try:
             sdkroot = os.environ['SDKROOT']
         except KeyError:
             sdkroot = '/'
             os.environ['SDKROOT'] = sdkroot
             sdkroot_set = True
         pass
     pass

# build the 'setup' call
setup_code = """
setup(name="pyina",
    version='%s',
    description="MPI parallel map and cluster scheduling",
    long_description = '''%s''',
    author = 'Mike McKerns',
    maintainer = 'Mike McKerns',
    license = '3-clause BSD',
    platforms = ['Linux', 'Mac'],
    url = 'https://github.com/uqfoundation/pyina',
    download_url = 'https://github.com/uqfoundation/pyina/archive/master.zip',
    classifiers = ['Development Status :: 5 - Production/Stable',
                   'Intended Audience :: Developers',
                   'Intended Audience :: Science/Research',
                   'License :: OSI Approved :: BSD License',
                   'Programming Language :: Python :: 2',
                   'Programming Language :: Python :: 2.7',
                   'Programming Language :: Python :: 3',
                   'Programming Language :: Python :: 3.6',
                   'Programming Language :: Python :: 3.7',
                   'Programming Language :: Python :: 3.8',
                   'Programming Language :: Python :: 3.9',
                   'Topic :: Scientific/Engineering',
                   'Topic :: Software Development'],

    packages=['pyina','pyina.tests'],
    package_dir={'pyina':'pyina','pyina.tests':'tests'},
""" % (target_version, long_description)

# add dependencies
from sys import version_info
sysversion = version_info[:2]
try:
    import ctypes # if using `pypy`, pythonapi is not found
    IS_PYPY = not hasattr(ctypes, 'pythonapi')
    IS_PYPY2 = IS_PYPY and sysversion < (3,0)
except:
    IS_PYPY = False
    IS_PYPY2 = False
if sysversion < (2,6) or sysversion == (3,0) or sysversion == (3,1):
    numpy_version = '>=1.0, <1.8.0'
elif sysversion == (2,6) or sysversion == (3,2) or sysversion == (3,3):
    numpy_version = '>=1.0, <1.12.0'
elif IS_PYPY2:
    numpy_version = '>=1.0, <1.16.0'
elif sysversion == (2,7) or sysversion == (3,4):
    numpy_version = '>=1.0, <1.17.0'
elif sysversion == (3,5):
    numpy_version = '>=1.0, <1.19.0'
elif sysversion == (3,6):# or IS_PYPY
    numpy_version = '>=1.0, <1.20.0'
else:
    numpy_version = '>=1.0'
dill_version = '>=0.3.4'
pox_version = '>=0.3.0'
pathos_version = '>=0.2.8'
mpi4py_version = '>=1.3, !=3.0.2' # segfault 11 on MPI import
pypar_version = '>=2.1.4'
mystic_version = '>=0.3.7'
# rtd fails for mpi4py, mock it instead
on_rtd = os.environ.get('READTHEDOCS', None) == 'True'
if has_setuptools:
    if on_rtd:
        setup_code += """
        zip_safe = False,
        install_requires = ('numpy%s', 'dill%s', 'pox%s', 'pathos%s'),
""" % (numpy_version, dill_version, pox_version, pathos_version)
    else:
        setup_code += """
        zip_safe = False,
        install_requires = ('numpy%s', 'mpi4py%s', 'dill%s', 'pox%s', 'pathos%s'),
""" % (numpy_version, mpi4py_version, dill_version, pox_version, pathos_version)

# add the scripts, and close 'setup' call
setup_code += """
    scripts=['scripts/ezpool','scripts/ezscatter','scripts/mpi_world'])
"""

# exec the 'setup' code
exec(setup_code)

# if dependencies are missing, print a warning
try:
    import numpy
    import dill
    import pox
    import pathos
    import mpi4py #XXX: throws an error even though ok?
    #import pypar
except ImportError:
    print("\n***********************************************************")
    print("WARNING: One of the following dependencies may be unresolved:")
    print(("    numpy %s" % numpy_version))
    print(("    dill %s" % dill_version))
    print(("    pox %s" % pox_version))
    print(("    pathos %s" % pathos_version))
    print(("    mpi4py %s" % mpi4py_version))
#   print("    pypar %s (optional)" % pypar_version)
    print("***********************************************************\n")

if sdkroot_set:
    print("\n***********************************************************")
    print("WARNING: One of following variables was set to a default:")
    print(("    SDKROOT %s" % sdkroot))
    print("***********************************************************\n")
else:
    pass

try:
    import mpi4py
except ImportError:
    print("""
You may need to set the environment variable "SDKROOT",
as shown in the instructions for installing ``mpi4py``:
  http://mpi4py.scipy.org/docs/usrman/install.html
""")


if __name__=='__main__':
    pass

# End of file
