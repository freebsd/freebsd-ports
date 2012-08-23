--- ./connectivity/source/sdbcx/VKeyColumn.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/sdbcx/VKeyColumn.cxx	2012-07-18 13:11:37.000000000 -0400
@@ -115,7 +115,7 @@
 void OKeyColumn::construct()
 {
     sal_Int32 nAttrib = isNew() ? 0 : PropertyAttribute::READONLY;
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_RELATEDCOLUMN),   PROPERTY_ID_RELATEDCOLUMN,  nAttrib,&m_ReferencedColumn,    ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_RELATEDCOLUMN),   PROPERTY_ID_RELATEDCOLUMN,  nAttrib,&m_ReferencedColumn,    ::getCppuType(static_cast< ::rtl::OUString*>(0)));
 }
 // -----------------------------------------------------------------------------
 
