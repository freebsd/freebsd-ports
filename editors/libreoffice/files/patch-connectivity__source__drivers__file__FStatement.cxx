--- ./connectivity/source/drivers/file/FStatement.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/drivers/file/FStatement.cxx	2012-07-18 13:31:40.000000000 -0400
@@ -93,16 +93,16 @@
 
     sal_Int32 nAttrib = 0;
 
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_CURSORNAME),      PROPERTY_ID_CURSORNAME,         nAttrib,&m_aCursorName,     ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_MAXFIELDSIZE),    PROPERTY_ID_MAXFIELDSIZE,       nAttrib,&m_nMaxFieldSize,       ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_MAXROWS),         PROPERTY_ID_MAXROWS,            nAttrib,&m_nMaxRows,        ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_QUERYTIMEOUT),    PROPERTY_ID_QUERYTIMEOUT,       nAttrib,&m_nQueryTimeOut,   ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_FETCHSIZE),       PROPERTY_ID_FETCHSIZE,          nAttrib,&m_nFetchSize,      ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_RESULTSETTYPE),   PROPERTY_ID_RESULTSETTYPE,      nAttrib,&m_nResultSetType,  ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_FETCHDIRECTION),  PROPERTY_ID_FETCHDIRECTION,     nAttrib,&m_nFetchDirection, ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_CURSORNAME),      PROPERTY_ID_CURSORNAME,         nAttrib,&m_aCursorName,     ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_MAXFIELDSIZE),    PROPERTY_ID_MAXFIELDSIZE,       nAttrib,&m_nMaxFieldSize,       ::getCppuType(static_cast<sal_Int32*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_MAXROWS),         PROPERTY_ID_MAXROWS,            nAttrib,&m_nMaxRows,        ::getCppuType(static_cast<sal_Int32*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_QUERYTIMEOUT),    PROPERTY_ID_QUERYTIMEOUT,       nAttrib,&m_nQueryTimeOut,   ::getCppuType(static_cast<sal_Int32*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_FETCHSIZE),       PROPERTY_ID_FETCHSIZE,          nAttrib,&m_nFetchSize,      ::getCppuType(static_cast<sal_Int32*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_RESULTSETTYPE),   PROPERTY_ID_RESULTSETTYPE,      nAttrib,&m_nResultSetType,  ::getCppuType(static_cast<sal_Int32*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_FETCHDIRECTION),  PROPERTY_ID_FETCHDIRECTION,     nAttrib,&m_nFetchDirection, ::getCppuType(static_cast<sal_Int32*>(0)));
     registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_ESCAPEPROCESSING),PROPERTY_ID_ESCAPEPROCESSING,   nAttrib,&m_bEscapeProcessing,::getCppuBooleanType());
 
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_RESULTSETCONCURRENCY),        PROPERTY_ID_RESULTSETCONCURRENCY,   nAttrib,&m_nResultSetConcurrency,       ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_RESULTSETCONCURRENCY),        PROPERTY_ID_RESULTSETCONCURRENCY,   nAttrib,&m_nResultSetConcurrency,       ::getCppuType(static_cast<sal_Int32*>(0)));
 }
 // -----------------------------------------------------------------------------
 OStatement_Base::~OStatement_Base()
