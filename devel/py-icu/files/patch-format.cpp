--- ./format.cpp.orig	2010-12-10 22:25:44.000000000 +0100
+++ ./format.cpp	2011-07-10 22:21:04.787715370 +0200
@@ -31,6 +31,10 @@
 #include "dateformat.h"
 #include "numberformat.h"
 
+#if U_ICU_VERSION_HEX >= 0x04080000
+	DECLARE_CONSTANTS_TYPE(UTimeUnitFormatStyle);
+#endif
+
 /* FieldPosition */
 
 class t_fieldposition : public _wrapper {
@@ -728,7 +732,11 @@
 static int t_timeunitformat_init(t_timeunitformat *self,
                                  PyObject *args, PyObject *kwds)
 {
+#if U_ICU_VERSION_HEX >= 0x04080000
+    UTimeUnitFormatStyle style;
+#else
     TimeUnitFormat::EStyle style;
+#endif
     Locale *locale;
 
     switch (PyTuple_Size(args)) {
@@ -1712,8 +1720,13 @@
 
     INSTALL_STATIC_INT(FieldPosition, DONT_CARE);
 
-#if U_ICU_VERSION_HEX >= 0x04020000
+#if U_ICU_VERSION_HEX >= 0x04020000 && U_ICU_VERSION_HEX < 0x04080000
     INSTALL_STATIC_INT(TimeUnitFormat, kFull);
     INSTALL_STATIC_INT(TimeUnitFormat, kAbbreviate);
 #endif
+#if U_ICU_VERSION_HEX >= 0x04080000
+    INSTALL_CONSTANTS_TYPE(UTimeUnitFormatStyle, m);
+    INSTALL_ENUM(UTimeUnitFormatStyle, "FULL", UTMUTFMT_FULL_STYLE);
+    INSTALL_ENUM(UTimeUnitFormatStyle, "ABBREVIATED", UTMUTFMT_ABBREVIATED_STYLE);
+#endif
 }
