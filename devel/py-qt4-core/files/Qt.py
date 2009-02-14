# Replacement for the composite module PyQt4.Qt for FreeBSD
# Provides namespace for all installed PyQt4 modules by importing them

from PyQt4.QtCore import *

try:
    from PyQt4.QtGui import *
except ImportError:
    pass
try:
    from PyQt4.QtXml import *
except ImportError:
    pass
try:
    from PyQt4.QtXmlPatterns import *
except ImportError:
    pass
try:
    from PyQt4.QtAssistant import *
except ImportError:
    pass
try:
    from PyQt4.QtDesigner import *
except ImportError:
    pass
try:
    from PyQt4.QtNetwork import *
except ImportError:
    pass
try:
    from PyQt4.QtOpenGL import *
except ImportError:
    pass
try:
    from PyQt4.QtScript import *
except ImportError:
    pass
try:
    from PyQt4.QtSql import *
except ImportError:
    pass
try:
    from PyQt4.QtSvg import *
except ImportError:
    pass
try:
    from PyQt4.QtTest import *
except ImportError:
    pass
try:
    from PyQt4.QtHelp import *
except ImportError:
    pass
try:
    from PyQt4.QtWebKit import *
except ImportError:
    pass
try:
    from PyQt4.phonon import *
except ImportError:
    pass
try:
    from PyQt4.Qsci import *
except:
    pass
