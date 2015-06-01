import os
import sys

basedir = os.environ["WRKSRC"]
sys.path.append(basedir)

import py.path
from pypy.tool.release.package import create_cffi_import_libraries, cffi_build_scripts

class Options(object):
    def __init__(self, options):
        for opt in options:
            setattr(self, 'no_' + opt, False)

create_cffi_import_libraries(sys.executable, Options(cffi_build_scripts), py.path.local(basedir))
