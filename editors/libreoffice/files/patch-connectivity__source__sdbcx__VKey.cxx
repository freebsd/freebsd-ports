--- ./connectivity/source/sdbcx/VKey.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/sdbcx/VKey.cxx	2012-07-18 13:16:00.000000000 -0400
@@ -139,10 +139,10 @@
 
     sal_Int32 nAttrib = isNew() ? 0 : PropertyAttribute::READONLY;
 
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_REFERENCEDTABLE), PROPERTY_ID_REFERENCEDTABLE,    nAttrib,&m_aProps->m_ReferencedTable,   ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_TYPE),            PROPERTY_ID_TYPE,               nAttrib,&m_aProps->m_Type,          ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_UPDATERULE),      PROPERTY_ID_UPDATERULE,         nAttrib,&m_aProps->m_UpdateRule,        ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_DELETERULE),      PROPERTY_ID_DELETERULE,         nAttrib,&m_aProps->m_DeleteRule,        ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_REFERENCEDTABLE), PROPERTY_ID_REFERENCEDTABLE,    nAttrib,&m_aProps->m_ReferencedTable,   ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_TYPE),            PROPERTY_ID_TYPE,               nAttrib,&m_aProps->m_Type,          ::getCppuType(static_cast<sal_Int32*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_UPDATERULE),      PROPERTY_ID_UPDATERULE,         nAttrib,&m_aProps->m_UpdateRule,        ::getCppuType(static_cast<sal_Int32*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_DELETERULE),      PROPERTY_ID_DELETERULE,         nAttrib,&m_aProps->m_DeleteRule,        ::getCppuType(static_cast<sal_Int32*>(0)));
 }
 // -------------------------------------------------------------------------
 void SAL_CALL OKey::disposing()
