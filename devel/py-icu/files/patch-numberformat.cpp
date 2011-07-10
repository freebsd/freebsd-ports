--- ./numberformat.cpp.orig	2010-04-16 04:29:22.000000000 +0200
+++ ./numberformat.cpp	2011-07-10 22:23:26.996346842 +0200
@@ -30,6 +30,10 @@
 #include "numberformat.h"
 #include "macros.h"
 
+#if U_ICU_VERSION_HEX >= 0x04080000
+    DECLARE_CONSTANTS_TYPE(UCurrencySpacing);
+#endif
+
 /* DecimalFormatSymbols */
 
 class t_decimalformatsymbols : public _wrapper {
@@ -502,7 +506,11 @@
 
 static PyObject *t_decimalformatsymbols_getPatternForCurrencySpacing(t_decimalformatsymbols *self, PyObject *args)
 {
+#if U_ICU_VERSION_HEX >= 0x04080000
+    UCurrencySpacing type;
+#else
     DecimalFormatSymbols::ECurrencySpacing type;
+#endif
     UBool beforeCurrency;
 
     if (!parseArgs(args, "ib", &type, &beforeCurrency))
@@ -518,7 +526,11 @@
 static PyObject *t_decimalformatsymbols_setPatternForCurrencySpacing(t_decimalformatsymbols *self, PyObject *args)
 {
     UnicodeString *u, _u;
+#if U_ICU_VERSION_HEX >= 0x04080000
+    UCurrencySpacing type;
+#else
     DecimalFormatSymbols::ECurrencySpacing type;
+#endif
     UBool beforeCurrency;
 
     if (!parseArgs(args, "ibS", &type, &beforeCurrency, &u, &_u))
@@ -2286,12 +2298,18 @@
     INSTALL_STATIC_INT(DecimalFormatSymbols, kNaNSymbol);
     INSTALL_STATIC_INT(DecimalFormatSymbols, kSignificantDigitSymbol);
 
-#if U_ICU_VERSION_HEX >= 0x04020000
+#if U_ICU_VERSION_HEX >= 0x04020000 && U_ICU_VERSION_HEX < 0x04080000
     INSTALL_STATIC_INT(DecimalFormatSymbols, kCurrencyMatch);
     INSTALL_STATIC_INT(DecimalFormatSymbols, kSurroundingMatch);
     INSTALL_STATIC_INT(DecimalFormatSymbols, kInsert);
     INSTALL_STATIC_INT(DecimalFormatSymbols, kCurrencySpacingCount);
 #endif
+#if U_ICU_VERSION_HEX >= 0x04080000
+    INSTALL_CONSTANTS_TYPE(UCurrencySpacing, m);
+    INSTALL_ENUM(UCurrencySpacing, "MATCH", UNUM_CURRENCY_MATCH);
+    INSTALL_ENUM(UCurrencySpacing, "SURROUNDING_MATCH", UNUM_CURRENCY_SURROUNDING_MATCH);
+    INSTALL_ENUM(UCurrencySpacing, "INSERT", UNUM_CURRENCY_INSERT);
+#endif
 
     INSTALL_STATIC_INT(NumberFormat, kIntegerField);
     INSTALL_STATIC_INT(NumberFormat, kFractionField);
