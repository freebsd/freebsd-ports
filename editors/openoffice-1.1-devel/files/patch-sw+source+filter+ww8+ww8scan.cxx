--- ../sw/source/filter/ww8/ww8scan.cxx.orig 2003-12-17 19:32:50.000000000 +0100
+++ ../sw/source/filter/ww8/ww8scan.cxx	2004-01-06 06:29:48.000000000 +0100
@@ -198,8 +198,13 @@
                 ++pIter;
         }
         if (bBroken)
+#if defined( UNX ) && !defined( DBG_UTIL )
+            DBG_ERROR(rtl::OUStringToOString(sError, RTL_TEXTENCODING_ASCII_US));
+#else
             DbgError(rtl::OUStringToOString(sError, RTL_TEXTENCODING_ASCII_US));
 #endif
+
+#endif
     }
 
     //Find an entry, return its address if found and 0 if not
