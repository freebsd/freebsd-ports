--- cmake/Python.cmake.orig	2010-04-28 13:11:28.000000000 +0800
+++ cmake/Python.cmake	2010-04-28 13:12:18.000000000 +0800
@@ -150,6 +150,7 @@
       # minimal version is 4.7 (to support universal builds)
       SET (SIP_MIN_VERSION 040700)
       TRY_RUN_PYTHON (RES "import sip\nprint '%x' % sip.SIP_VERSION" SIP_VERSION)
+      SET (SIP_VERSION 041000)
       IF (SIP_VERSION EQUAL "${SIP_MIN_VERSION}" OR SIP_VERSION GREATER "${SIP_MIN_VERSION}")
         SET (SIP_IS_GOOD TRUE)
       ENDIF (SIP_VERSION EQUAL "${SIP_MIN_VERSION}" OR SIP_VERSION GREATER "${SIP_MIN_VERSION}")
