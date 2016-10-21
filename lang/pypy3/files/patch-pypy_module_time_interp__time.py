--- pypy/module/time/interp_time.py.orig	2016-10-12 19:05:22 UTC
+++ pypy/module/time/interp_time.py
@@ -4,8 +4,7 @@ from pypy.interpreter.error import Opera
 from pypy.interpreter.gateway import unwrap_spec
 from rpython.rtyper.lltypesystem import lltype
 from rpython.rlib.rarithmetic import intmask, r_ulonglong, r_longfloat, widen
-from rpython.rlib.rtime import (TIMEB, c_ftime,
-                                GETTIMEOFDAY_NO_TZ, TIMEVAL,
+from rpython.rlib.rtime import (GETTIMEOFDAY_NO_TZ, TIMEVAL,
                                 HAVE_GETTIMEOFDAY, HAVE_FTIME)
 from rpython.rlib import rposix, rtime
 from rpython.translator.tool.cbuild import ExternalCompilationInfo
@@ -14,6 +13,9 @@ import os
 import sys
 import time as pytime
 
+if HAVE_FTIME:
+    from rpython.rlib.rtime import TIMEB, c_ftime
+
 _POSIX = os.name == "posix"
 _WIN = os.name == "nt"
 _MACOSX = sys.platform == "darwin"
