Fixes build on FreeBSD 10.* with ICU >= 59

In file included from icu.cpp:34:
In file included from /usr/local/include/unicode/utypes.h:38:
/usr/local/include/unicode/umachine.h:347:13: error: unknown type name 'char16_t'
    typedef char16_t UChar;
            ^

--- src/qt/qtbase/config.tests/unix/icu/icu.pro.orig	2015-12-12 12:58:05 UTC
+++ src/qt/qtbase/config.tests/unix/icu/icu.pro
@@ -1,5 +1,5 @@
 SOURCES = icu.cpp
-CONFIG += console
+CONFIG += c++11 console
 CONFIG -= qt dylib
 
 include($$PWD/../../../src/3rdparty/icu_dependency.pri)
