--- ./connectivity/source/drivers/ado/AKeyColumn.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/drivers/ado/AKeyColumn.cxx	2012-07-18 14:50:16.000000000 -0400
@@ -63,7 +63,7 @@
 void OKeyColumn::construct()
 {
     sal_Int32 nAttrib = isNew() ? 0 : starbeans::PropertyAttribute::READONLY;
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_RELATEDCOLUMN),   PROPERTY_ID_RELATEDCOLUMN,  nAttrib,&m_ReferencedColumn,    ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_RELATEDCOLUMN),   PROPERTY_ID_RELATEDCOLUMN,  nAttrib,&m_ReferencedColumn,    ::getCppuType(static_cast< ::rtl::OUString*>(0)));
 }
 
 /* vim:set shiftwidth=4 softtabstop=4 expandtab: */
