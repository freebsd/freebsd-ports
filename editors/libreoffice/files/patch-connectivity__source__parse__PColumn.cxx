--- ./connectivity/source/parse/PColumn.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/parse/PColumn.cxx	2012-07-18 17:07:31.000000000 -0400
@@ -176,13 +176,13 @@
 // -------------------------------------------------------------------------
 void OParseColumn::construct()
 {
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_FUNCTION),                PROPERTY_ID_FUNCTION,               0,  &m_bFunction,               ::getCppuType(reinterpret_cast< sal_Bool*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_AGGREGATEFUNCTION),       PROPERTY_ID_AGGREGATEFUNCTION,      0,  &m_bAggregateFunction,      ::getCppuType(reinterpret_cast< sal_Bool*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_TABLENAME),               PROPERTY_ID_TABLENAME,              0,  &m_aTableName,              ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_REALNAME),                PROPERTY_ID_REALNAME,               0,  &m_aRealName,               ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_DBASEPRECISIONCHANGED),   PROPERTY_ID_DBASEPRECISIONCHANGED,  0,  &m_bDbasePrecisionChanged,  ::getCppuType(reinterpret_cast<sal_Bool*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_ISSEARCHABLE),            PROPERTY_ID_ISSEARCHABLE,           0,  &m_bIsSearchable,           ::getCppuType(reinterpret_cast< sal_Bool*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_LABEL),                   PROPERTY_ID_LABEL,                  0,  &m_sLabel,                  ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_FUNCTION),                PROPERTY_ID_FUNCTION,               0,  &m_bFunction,               ::getCppuType(static_cast< sal_Bool*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_AGGREGATEFUNCTION),       PROPERTY_ID_AGGREGATEFUNCTION,      0,  &m_bAggregateFunction,      ::getCppuType(static_cast< sal_Bool*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_TABLENAME),               PROPERTY_ID_TABLENAME,              0,  &m_aTableName,              ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_REALNAME),                PROPERTY_ID_REALNAME,               0,  &m_aRealName,               ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_DBASEPRECISIONCHANGED),   PROPERTY_ID_DBASEPRECISIONCHANGED,  0,  &m_bDbasePrecisionChanged,  ::getCppuType(static_cast<sal_Bool*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_ISSEARCHABLE),            PROPERTY_ID_ISSEARCHABLE,           0,  &m_bIsSearchable,           ::getCppuType(static_cast< sal_Bool*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_LABEL),                   PROPERTY_ID_LABEL,                  0,  &m_sLabel,                  ::getCppuType(static_cast< ::rtl::OUString*>(0)));
 }
 // -----------------------------------------------------------------------------
 ::cppu::IPropertyArrayHelper* OParseColumn::createArrayHelper() const
@@ -268,9 +268,9 @@
 void OOrderColumn::construct()
 {
     registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_ISASCENDING), PROPERTY_ID_ISASCENDING,
-        PropertyAttribute::READONLY,  const_cast< sal_Bool* >( &m_bAscending ),    ::getCppuType( reinterpret_cast< sal_Bool* >( NULL ) ) );
+        PropertyAttribute::READONLY,  const_cast< sal_Bool* >( &m_bAscending ),    ::getCppuType( static_cast< sal_Bool* >( 0 ) ) );
     registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_TABLENAME),   PROPERTY_ID_TABLENAME,
-        PropertyAttribute::READONLY,  const_cast< ::rtl::OUString* >( &m_sTableName ),  ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
+        PropertyAttribute::READONLY,  const_cast< ::rtl::OUString* >( &m_sTableName ),  ::getCppuType(static_cast< ::rtl::OUString*>(0)));
 }
 // -----------------------------------------------------------------------------
 ::cppu::IPropertyArrayHelper* OOrderColumn::createArrayHelper() const
