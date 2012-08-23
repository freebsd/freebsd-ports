--- ./connectivity/source/sdbcx/VIndex.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/sdbcx/VIndex.cxx	2012-07-18 13:17:23.000000000 -0400
@@ -142,7 +142,7 @@
 
     sal_Int32 nAttrib = isNew() ? 0 : PropertyAttribute::READONLY;
 
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_CATALOG),         PROPERTY_ID_CATALOG,            nAttrib,&m_Catalog,         ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_CATALOG),         PROPERTY_ID_CATALOG,            nAttrib,&m_Catalog,         ::getCppuType(static_cast< ::rtl::OUString*>(0)));
     registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_ISUNIQUE),            PROPERTY_ID_ISUNIQUE,           nAttrib,&m_IsUnique,            ::getBooleanCppuType());
     registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_ISPRIMARYKEYINDEX),PROPERTY_ID_ISPRIMARYKEYINDEX, nAttrib,&m_IsPrimaryKeyIndex,   ::getBooleanCppuType());
     registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_ISCLUSTERED),     PROPERTY_ID_ISCLUSTERED,        nAttrib,&m_IsClustered,     ::getBooleanCppuType());
