--- gsoap/stdsoap2.h.orig	2008-01-27 22:02:36.000000000 +0100
+++ gsoap/stdsoap2.h	2008-07-04 12:35:55.000000000 +0200
@@ -314,9 +314,6 @@
 #  define HAVE_STRRCHR
 #  define HAVE_STRTOD
 #  define HAVE_SSCANF
-#  define HAVE_STRTOD_L
-#  define HAVE_SSCANF_L
-#  define HAVE_SPRINTF_L
 #  define HAVE_STRTOL
 #  define HAVE_STRTOUL
 #  define HAVE_STRTOLL
@@ -1462,9 +1465,9 @@
 # endif
 # ifndef DBGFUN
 #  define DBGFUN(FNAME) DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%s(%d): %s()\n", __FILE__, __LINE__, FNAME))
-#  define DBGFUN1(FNAME, FMT, ARG) DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%s(%d): %s("FMT")\n", __FILE__, __LINE__, FNAME, (ARG)))
-#  define DBGFUN2(FNAME, FMT1, ARG1, FMT2, ARG2) DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%s(%d): %s("FMT1", "FMT2")\n", __FILE__, __LINE__, FNAME, (ARG1), (ARG2)))
-#  define DBGFUN3(FNAME, FMT1, ARG1, FMT2, ARG2, FMT3, ARG3) DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%s(%d): %s("FMT1", "FMT2", "FMT3")\n", __FILE__, __LINE__, FNAME, (ARG1), (ARG2), (ARG3)))
+#  define DBGFUN1(FNAME, FMT, ARG) DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%s(%d): %s(" FMT ")\n", __FILE__, __LINE__, FNAME, (ARG)))
+#  define DBGFUN2(FNAME, FMT1, ARG1, FMT2, ARG2) DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%s(%d): %s(" FMT1 ", " FMT2 ")\n", __FILE__, __LINE__, FNAME, (ARG1), (ARG2)))
+#  define DBGFUN3(FNAME, FMT1, ARG1, FMT2, ARG2, FMT3, ARG3) DBGLOG(TEST, SOAP_MESSAGE(fdebug, "%s(%d): %s(" FMT1 ", " FMT2 ", " FMT3 ")\n", __FILE__, __LINE__, FNAME, (ARG1), (ARG2), (ARG3)))
 # endif
 # ifndef DBGHEX
 #  define DBGHEX(DBGFILE, MSG, LEN) \
