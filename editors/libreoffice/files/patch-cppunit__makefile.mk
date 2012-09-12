--- ./cppunit/makefile.mk.orig	2012-08-08 09:00:06.000000000 -0400
+++ ./cppunit/makefile.mk	2012-09-10 20:26:04.000000000 -0400
@@ -34,7 +34,7 @@
     # from <https://sourceforge.net/projects/cppunit/files/cppunit/1.12.1/
     #  cppunit-1.12.1.tar.gz/download>
 
-PATCH_FILES = solarisfinite.patch warnings.patch windows.patch ldflags.patch aix.patch avoid-synthetised-destructor.patch ios.patch
+PATCH_FILES = solarisfinite.patch warnings.patch windows.patch ldflags.patch aix.patch avoid-synthetised-destructor.patch ios.patch gcc-abi-demangle.patch
     # solarisfinite.patch: see <https://sourceforge.net/tracker/?func=detail&
     #  aid=2912590&group_id=11795&atid=311795>
     # warnings.patch: see <https://sourceforge.net/tracker/?func=detail&
@@ -44,6 +44,10 @@
 PATCH_FILES += android.patch
 .ENDIF
 
+.IF "$(OS)" == "FREEBSD"
+PATCH_FILES += freebsd.patch
+.ENDIF
+
 .IF "$(OS)" == "WNT"
 .IF "$(COM)" == "MSC"
 
