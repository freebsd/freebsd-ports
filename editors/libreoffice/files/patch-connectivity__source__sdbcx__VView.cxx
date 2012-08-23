--- ./connectivity/source/sdbcx/VView.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/sdbcx/VView.cxx	2012-07-18 13:21:10.000000000 -0400
@@ -78,10 +78,10 @@
 
     sal_Int32 nAttrib = isNew() ? 0 : PropertyAttribute::READONLY;
 
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_CATALOGNAME),     PROPERTY_ID_CATALOGNAME,nAttrib,&m_CatalogName, ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_SCHEMANAME),      PROPERTY_ID_SCHEMANAME, nAttrib,&m_SchemaName,  ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_COMMAND),         PROPERTY_ID_COMMAND,    nAttrib,&m_Command,     ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_CHECKOPTION),     PROPERTY_ID_CHECKOPTION,nAttrib,&m_CheckOption, ::getCppuType(reinterpret_cast< sal_Int32*>(NULL)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_CATALOGNAME),     PROPERTY_ID_CATALOGNAME,nAttrib,&m_CatalogName, ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_SCHEMANAME),      PROPERTY_ID_SCHEMANAME, nAttrib,&m_SchemaName,  ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_COMMAND),         PROPERTY_ID_COMMAND,    nAttrib,&m_Command,     ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_CHECKOPTION),     PROPERTY_ID_CHECKOPTION,nAttrib,&m_CheckOption, ::getCppuType(static_cast< sal_Int32*>(0)));
 }
 // -------------------------------------------------------------------------
 void OView::disposing(void)
