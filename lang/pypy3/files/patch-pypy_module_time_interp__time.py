--- pypy/module/time/interp_time.py.orig	2016-05-29 20:38:19 UTC
+++ pypy/module/time/interp_time.py
@@ -4,6 +4,7 @@ from pypy.interpreter.error import Opera
 from pypy.interpreter.gateway import unwrap_spec
 from rpython.rtyper.lltypesystem import lltype
 from rpython.rlib.rarithmetic import intmask
+from rpython.rlib.rposix import CLOCK_T as clock_t
 from rpython.rlib.rtime import win_perf_counter
 from rpython.rlib import rposix, rtime
 from rpython.translator.tool.cbuild import ExternalCompilationInfo
@@ -147,7 +148,6 @@ class CConfig:
         libraries=rtime.libraries
     )
     CLOCKS_PER_SEC = platform.ConstantInteger("CLOCKS_PER_SEC")
-    clock_t = platform.SimpleType("clock_t", rffi.ULONG)
     has_gettimeofday = platform.Has('gettimeofday')
     has_clock_gettime = platform.Has('clock_gettime')
     CLOCK_PROF = platform.DefinedConstantInteger('CLOCK_PROF')
@@ -224,7 +224,6 @@ if _POSIX:
 
 CLOCKS_PER_SEC = cConfig.CLOCKS_PER_SEC
 HAS_CLOCK_GETTIME = cConfig.has_clock_gettime
-clock_t = cConfig.clock_t
 tm = cConfig.tm
 glob_buf = lltype.malloc(tm, flavor='raw', zero=True, immortal=True)
 
@@ -966,7 +965,9 @@ else:
             with lltype.scoped_alloc(rposix.TMS) as tms:
                 ret = rposix.c_times(tms)
                 if rffi.cast(lltype.Signed, ret) != -1:
-                    cpu_time = float(tms.c_tms_utime + tms.c_tms_stime)
+                    c_tms_utime = rffi.cast(lltype.Signed, tms.c_tms_utime)
+                    c_tms_stime = rffi.cast(lltype.Signed, tms.c_tms_stime)
+                    cpu_time = float(c_tms_utime + c_tms_stime)
                     if w_info is not None:
                         _setinfo(space, w_info, "times()",
                                  1.0 / rposix.CLOCK_TICKS_PER_SECOND,
@@ -993,7 +994,7 @@ else:
         records."""
         value = _clock()
         # Is this casting correct?
-        if value == rffi.cast(clock_t, -1):
+        if intmask(value) == intmask(rffi.cast(clock_t, -1)):
             raise oefmt(space.w_RuntimeError,
                         "the processor time used is not available or its value"
                         "cannot be represented")
