--- stlport/stl/c_locale.h.orig	Wed Jul 24 03:17:57 2002
+++ stlport/stl/c_locale.h	Wed Jul 24 03:19:25 2002
@@ -178,7 +178,7 @@
                            _Locale_SPACE ) /* Printable */
 # endif /* __Lynx__ */
 
-#if defined(__GNUC__) || defined (__BORLANDC__) || defined (__COMO__)
+#if defined(__GNUC__) || defined (__BORLANDC__) || defined (__COMO__) || defined (__ICC)
 
 # if defined (__CYGWIN__)
 
