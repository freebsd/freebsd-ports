--- stlport/stl/c_locale.h.orig	Sun Nov  2 16:59:03 2003
+++ stlport/stl/c_locale.h	Sat Nov  6 15:44:22 2004
@@ -178,7 +178,7 @@
                            _Locale_SPACE ) /* Printable */
 # endif /* __Lynx__ */
 
-#if defined(__GNUC__) || defined (__BORLANDC__) || defined (__COMO__)
+#if defined(__GNUC__) || defined (__BORLANDC__) || defined (__COMO__) || defined (__ICC)
 
 # if defined (__CYGWIN__)
 
