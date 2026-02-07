--- mimelib/string.cpp.bak	1997-09-27 13:54:17.000000000 +0200
+++ mimelib/string.cpp	2011-01-20 11:16:24.000000000 +0100
@@ -29,7 +29,7 @@
 #include <ctype.h>
 #include <stdlib.h>
 #include <string.h>
-#include <new.h>
+#include <new>
 #include <mimelib/string.h>
 
 #define DW_MIN(a,b) ((a) <= (b) ? (a) : (b))
@@ -138,9 +138,9 @@
     assert(rep != 0);
 #if defined(DW_DEBUG_VERSION) || defined(DW_DEVELOPMENT_VERSION)
     if (rep->mRefCount <= 0) {
-        cerr << "Error: attempt to delete a DwStringRep "
+        std::cerr << "Error: attempt to delete a DwStringRep "
             "with ref count <= 0\n";
-        cerr << "(Possibly 'delete' was called twice for same object)\n";
+        std::cerr << "(Possibly 'delete' was called twice for same object)\n";
         abort();
     }
 #endif //  defined(DW_DEBUG_VERSION) || defined(DW_DEVELOPMENT_VERSION)
@@ -173,8 +173,8 @@
 {
 #if defined (DW_DEBUG_VERSION) || defined (DW_DEVELOPMENT_VERSION)
     if (mBuffer == 0) {
-        cerr << "DwStringRep destructor called for bad DwStringRep object\n";
-        cerr << "(Possibly 'delete' was called twice for same object)\n";
+        std::cerr << "DwStringRep destructor called for bad DwStringRep object\n";
+        std::cerr << "(Possibly 'delete' was called twice for same object)\n";
         abort();
     }
 #endif //  defined (DW_DEBUG_VERSION) || defined (DW_DEVELOPMENT_VERSION)
@@ -1045,7 +1045,7 @@
 }
 
 
-void DwString::WriteTo(ostream& aStrm) const
+void DwString::WriteTo(std::ostream& aStrm) const
 {
     const char* buf = mRep->mBuffer + mStart;
     for (size_t i=0; i < mLength; ++i) {
@@ -1336,7 +1336,7 @@
 }
 
 
-void DwString::PrintDebugInfo(ostream& aStrm) const
+void DwString::PrintDebugInfo(std::ostream& aStrm) const
 {
 #if defined (DW_DEBUG_VERSION)
     aStrm << 
@@ -1633,7 +1633,7 @@
 }
 
 
-ostream& operator << (ostream& aOstrm, const DwString& aStr)
+std::ostream& operator << (std::ostream& aOstrm, const DwString& aStr)
 {
     const char* buf = aStr.data();
     for (size_t i=0; i < aStr.length(); ++i) {
@@ -1643,7 +1643,7 @@
 }
 
 
-istream& getline(istream& aIstrm, DwString& aStr, char aDelim)
+std::istream& getline(std::istream& aIstrm, DwString& aStr, char aDelim)
 {
     aStr.clear();
     char ch;
@@ -1657,7 +1657,7 @@
 }
 
 
-istream& getline(istream& aIstrm, DwString& aStr)
+std::istream& getline(std::istream& aIstrm, DwString& aStr)
 {
     return getline(aIstrm, aStr, '\n');
 }
