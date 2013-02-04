--- ./cppunit/makefile.mk.orig	2013-01-16 04:41:51.000000000 -0500
+++ ./cppunit/makefile.mk	2013-01-31 15:27:50.000000000 -0500
@@ -34,7 +34,7 @@
     # from <https://sourceforge.net/projects/cppunit/files/cppunit/1.12.1/
     #  cppunit-1.12.1.tar.gz/download>
 
-PATCH_FILES = solarisfinite.patch warnings.patch windows.patch ldflags.patch aix.patch avoid-synthetised-destructor.patch ios.patch cppunit-1.12.1-unused-parameters.patch cppunit-1.12.1-warnings.patch
+PATCH_FILES = solarisfinite.patch warnings.patch windows.patch ldflags.patch aix.patch avoid-synthetised-destructor.patch ios.patch cppunit-1.12.1-unused-parameters.patch cppunit-1.12.1-warnings.patch gcc-abi-demangle.patch
     # solarisfinite.patch: see <https://sourceforge.net/tracker/?func=detail&
     #  aid=2912590&group_id=11795&atid=311795>; upstreamed as
     #  <http://cgit.freedesktop.org/libreoffice/cppunit/commit/?id=
@@ -64,6 +64,10 @@
 PATCH_FILES += android.patch
 .ENDIF
 
+.IF "$(OS)" == "FREEBSD"
+PATCH_FILES += freebsd.patch
+.ENDIF
+
 .IF "$(OS)" == "WNT"
 .IF "$(COM)" == "MSC"
 
