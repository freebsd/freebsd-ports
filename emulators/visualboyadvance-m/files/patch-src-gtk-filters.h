--- src/gtk/filters.h.orig	2011-02-20 00:33:53.000000000 +0300
+++ src/gtk/filters.h	2011-08-04 21:06:06.000000000 +0400
@@ -64,10 +64,10 @@
 };
 
 Filter pvGetFilter(EFilter _eFilter, EFilterDepth _eDepth);
-char* pcsGetFilterName(const EFilter _eFilter);
+const char* pcsGetFilterName(const EFilter _eFilter);
 
 FilterIB pvGetFilterIB(EFilterIB _eFilterIB, EFilterDepth _eDepth);
-char* pcsGetFilterIBName(const EFilterIB _eFilterIB);
+const char* pcsGetFilterIBName(const EFilterIB _eFilterIB);
 
 } // namespace VBA
 
