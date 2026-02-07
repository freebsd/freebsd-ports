--- config.tests/arch/arch.pro.orig	2021-05-26 21:40:42 UTC
+++ config.tests/arch/arch.pro
@@ -1,2 +1,3 @@
 SOURCES = arch.cpp
+QMAKE_CXXFLAGS += $$(CXXFLAGS)
 include(write_info.pri)
