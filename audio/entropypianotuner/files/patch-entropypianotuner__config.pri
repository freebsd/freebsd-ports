--- entropypianotuner_config.pri.orig	2026-03-13 19:54:30 UTC
+++ entropypianotuner_config.pri
@@ -72,4 +72,9 @@ win|linux:!android {
     packagesExist(libuv):  EPT_THIRDPARTY_CONFIG+=system_libuv
 }
 
+# FreeBSD change - use FreeBSD fftw3, libuv and qwt
+EPT_THIRDPARTY_CONFIG+=system_fftw3
+EPT_THIRDPARTY_CONFIG+=system_libuv
+EPT_THIRDPARTY_CONFIG+=system_qwt
+
 include($$PWD/entropypianotuner_static_config.pri)
