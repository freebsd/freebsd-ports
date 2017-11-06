--- dtrace_cython/dtrace_h.pxd.orig	2015-01-24 23:30:44 UTC
+++ dtrace_cython/dtrace_h.pxd
@@ -7,7 +7,7 @@ cdef extern from "libelf_workaround.h":
     pass
 
 
-IF UNAME_SYSNAME == "Darwin":
+IF UNAME_SYSNAME == "Darwin" or UNAME_SYSNAME == "FreeBSD":
     cdef extern from "stdint.h":
         # needed for quantize mths.
         cdef int64_t INT64_MAX
@@ -18,7 +18,6 @@ ELSE:
         cdef int64_t INT64_MAX
         cdef int64_t INT64_MIN
 
-
 cdef extern from "sys/dtrace.h":
 
     ctypedef enum agg_actions:
@@ -34,10 +33,12 @@ cdef extern from "sys/dtrace.h":
         DTRACEAGG_QUANTIZE = (DTRACEACT_AGGREGATION + 7)
         DTRACEAGG_LQUANTIZE = (DTRACEACT_AGGREGATION + 8)
 
-    ctypedef enum quantize_types:
+    cdef int DTRACE_QUANTIZE_NBUCKETS
+    cdef int DTRACE_QUANTIZE_ZEROBUCKET
+    #ctypedef enum quantize_types:
         # NBBY = 8
-        DTRACE_QUANTIZE_NBUCKETS = (((sizeof (uint64_t) * 8) - 1) * 2 + 1)
-        DTRACE_QUANTIZE_ZEROBUCKET = ((sizeof (uint64_t) * 8) - 1)
+    #    DTRACE_QUANTIZE_NBUCKETS = (((sizeof (uint64_t) * 8) - 1) * 2 + 1)
+    #    DTRACE_QUANTIZE_ZEROBUCKET = ((sizeof (uint64_t) * 8) - 1)
 
     ctypedef struct dtrace_recdesc_t:
         # Taken from sys/dtrace.h:931
@@ -56,7 +57,6 @@ cdef extern from "sys/dtrace.h":
     cdef int32_t DTRACE_LQUANTIZE_BASE(long x)
     cdef int64_t DTRACE_QUANTIZE_BUCKETVAL(long buck)
 
-
 cdef extern from "dtrace.h":
 
     ctypedef enum dtrace_probespec_t:
