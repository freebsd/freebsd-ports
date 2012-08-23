--- ./connectivity/source/commontools/FDatabaseMetaDataResultSet.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/commontools/FDatabaseMetaDataResultSet.cxx	2012-07-18 13:26:19.000000000 -0400
@@ -91,10 +91,10 @@
 // -------------------------------------------------------------------------
 void ODatabaseMetaDataResultSet::construct()
 {
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_FETCHSIZE),           PROPERTY_ID_FETCHSIZE,          0,&m_nFetchSize,        ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_RESULTSETTYPE),        PROPERTY_ID_RESULTSETTYPE,          PropertyAttribute::READONLY,&m_nResultSetType,       ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_FETCHDIRECTION),      PROPERTY_ID_FETCHDIRECTION,     0,  &m_nFetchDirection, ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_RESULTSETCONCURRENCY), PROPERTY_ID_RESULTSETCONCURRENCY,   PropertyAttribute::READONLY,&m_nResultSetConcurrency,                ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_FETCHSIZE),           PROPERTY_ID_FETCHSIZE,          0,&m_nFetchSize,        ::getCppuType(static_cast<sal_Int32*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_RESULTSETTYPE),        PROPERTY_ID_RESULTSETTYPE,          PropertyAttribute::READONLY,&m_nResultSetType,       ::getCppuType(static_cast<sal_Int32*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_FETCHDIRECTION),      PROPERTY_ID_FETCHDIRECTION,     0,  &m_nFetchDirection, ::getCppuType(static_cast<sal_Int32*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_RESULTSETCONCURRENCY), PROPERTY_ID_RESULTSETCONCURRENCY,   PropertyAttribute::READONLY,&m_nResultSetConcurrency,                ::getCppuType(static_cast<sal_Int32*>(0)));
 }
 // -----------------------------------------------------------------------------
 void ODatabaseMetaDataResultSet::setType(MetaDataResultSetType _eType)
