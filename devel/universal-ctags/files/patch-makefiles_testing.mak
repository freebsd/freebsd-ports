--- makefiles/testing.mak.orig	2021-09-26 04:43:19 UTC
+++ makefiles/testing.mak
@@ -5,7 +5,7 @@ EXTRA_DIST += misc/units misc/units.py misc/man-test.p
 EXTRA_DIST += misc/tlib misc/mini-geany.expected
 MAN_TEST_TMPDIR = ManTest
 
-check: tmain units tlib man-test check-genfile
+check: tmain units tlib man-test
 
 # We may use CLEANFILES, DISTCLEANFILES, or etc.
 # clean-tlib and clean-gcov are not included
