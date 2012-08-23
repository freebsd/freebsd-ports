--- ./connectivity/source/drivers/ado/AColumn.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/drivers/ado/AColumn.cxx	2012-07-18 14:48:46.000000000 -0400
@@ -117,7 +117,7 @@
     sal_Int32 nAttrib = isNew() ? 0 : PropertyAttribute::READONLY;
 
     registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_ISASCENDING),     PROPERTY_ID_ISASCENDING,    nAttrib,&m_IsAscending, ::getBooleanCppuType());
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_RELATEDCOLUMN),   PROPERTY_ID_RELATEDCOLUMN,  nAttrib,&m_ReferencedColumn,    ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_RELATEDCOLUMN),   PROPERTY_ID_RELATEDCOLUMN,  nAttrib,&m_ReferencedColumn,    ::getCppuType(static_cast< ::rtl::OUString*>(0)));
 }
 // -----------------------------------------------------------------------------
 void OAdoColumn::setFastPropertyValue_NoBroadcast(sal_Int32 nHandle,const Any& rValue)throw (Exception)
