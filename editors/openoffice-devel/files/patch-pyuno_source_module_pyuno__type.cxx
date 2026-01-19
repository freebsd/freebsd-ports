--- pyuno/source/module/pyuno_type.cxx.orig	2025-09-13 05:44:24 UTC
+++ pyuno/source/module/pyuno_type.cxx
@@ -150,7 +150,11 @@ sal_Unicode PyChar2Unicode( PyObject *obj ) throw ( Ru
             Reference< XInterface > () );
     }
 
+#if PY_VERSION_HEX >= 0x030C0000
+    if( PyUnicode_GetLength( value.get() ) < 1 )
+#else
     if( PyUnicode_GetSize( value.get() ) < 1 )
+#endif
     {
         throw RuntimeException(
             USTR_ASCII( "uno.Char contains an empty unicode string" ),
