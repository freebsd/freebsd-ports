--- mimelib/msgcmp.cpp.bak	1997-09-27 13:54:08.000000000 +0200
+++ mimelib/msgcmp.cpp	2011-01-20 11:13:04.000000000 +0100
@@ -76,8 +76,8 @@
 {
 #if defined (DW_DEBUG_VERSION) || defined (DW_DEVELOPMENT_VERSION)
     if (mMagicNumber != (DwUint32) kMagicNumber) {
-        cerr << "Bad value for 'this' in destructor\n";
-        cerr << "(Possibly 'delete' was called twice for same object)\n";
+        std::cerr << "Bad value for 'this' in destructor\n";
+        std::cerr << "(Possibly 'delete' was called twice for same object)\n";
         abort();
     }
     mMagicNumber = 0;
