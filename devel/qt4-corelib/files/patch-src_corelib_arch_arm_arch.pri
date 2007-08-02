--- src/corelib/arch/arm/arch.pri.orig	2007-05-25 15:24:41.000000000 +0200
+++ src/corelib/arch/arm/arch.pri	2007-07-25 20:23:32.000000000 +0200
@@ -1,5 +1,4 @@
 #
 # ARM architecture
 #
-SOURCES += $$QT_ARCH_CPP/qatomic.cpp \
-           $$QT_ARCH_CPP/malloc.c
+SOURCES += $$QT_ARCH_CPP/qatomic.cpp
