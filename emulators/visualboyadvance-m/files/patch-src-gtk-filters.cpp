--- src/gtk/filters.cpp.orig	2011-02-24 16:06:17.000000000 +0300
+++ src/gtk/filters.cpp	2011-08-04 21:05:59.000000000 +0400
@@ -87,7 +87,7 @@
   return astFilters[_eFilter].m_apvFunc[_eDepth];
 }
 
-char* pcsGetFilterName(const EFilter _eFilter)
+const char* pcsGetFilterName(const EFilter _eFilter)
 {
         return gettext(astFilters[_eFilter].m_csName);
 }
@@ -97,7 +97,7 @@
   return astFiltersIB[_eFilterIB].m_apvFunc[_eDepth];
 }
 
-char* pcsGetFilterIBName(const EFilterIB _eFilterIB)
+const char* pcsGetFilterIBName(const EFilterIB _eFilterIB)
 {
         return gettext(astFiltersIB[_eFilterIB].m_csName);
 }
