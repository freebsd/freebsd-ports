Disable building the tests.  They prevent building sonic-visualiser in parallel.
--- sonic-visualiser.pro.orig	2017-02-24 17:52:22 UTC
+++ sonic-visualiser.pro
@@ -5,7 +5,6 @@ SUBDIRS = sub_dataquay svcore svgui svap
     # We should build and run the tests on any platform,
     # but doing it automatically doesn't work so well from
     # within an IDE on Windows, so remove that from here
-    SUBDIRS += svcore/base/test svcore/data/fileio/test svcore/data/model/test
 }
 
 sub_sv.file = sv.pro
