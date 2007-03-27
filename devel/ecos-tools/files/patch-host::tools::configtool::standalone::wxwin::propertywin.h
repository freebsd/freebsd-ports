$FreeBSD$

--- ../ecos/host/tools/configtool/standalone/wxwin/propertywin.h.orig	Sat Jun  2 00:16:30 2001
+++ ../ecos/host/tools/configtool/standalone/wxwin/propertywin.h	Tue Mar 27 20:35:41 2007
@@ -93,8 +93,8 @@
     int m_nFirstProperty;
     ecConfigItem *m_pti;
 
-    static const std::string ecPropertyListCtrl::visible_properties [];
-	static const wxChar* sm_fieldTypeImage[ecMAXFIELDTYPE];
+    static const std::string visible_properties [];
+    static const wxChar* sm_fieldTypeImage[ecMAXFIELDTYPE];
 };
 
 
