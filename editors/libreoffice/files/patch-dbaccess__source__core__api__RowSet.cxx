--- ./dbaccess/source/core/api/RowSet.cxx.orig	2012-07-27 08:37:04.000000000 -0400
+++ ./dbaccess/source/core/api/RowSet.cxx	2012-07-31 19:44:15.000000000 -0400
@@ -178,45 +178,45 @@
     m_aPrematureParamValues.get().resize( 0 );
 
     // sdb.RowSet Properties
-    registerMayBeVoidProperty(PROPERTY_ACTIVE_CONNECTION,PROPERTY_ID_ACTIVE_CONNECTION, PropertyAttribute::MAYBEVOID|PropertyAttribute::TRANSIENT|PropertyAttribute::BOUND, &m_aActiveConnection,   ::getCppuType(reinterpret_cast< Reference< XConnection >* >(NULL)));
-    registerProperty(PROPERTY_DATASOURCENAME,       PROPERTY_ID_DATASOURCENAME,         PropertyAttribute::BOUND,       &m_aDataSourceName,     ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(PROPERTY_COMMAND,              PROPERTY_ID_COMMAND,                PropertyAttribute::BOUND,       &m_aCommand,            ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(PROPERTY_COMMAND_TYPE,         PROPERTY_ID_COMMAND_TYPE,           PropertyAttribute::BOUND,       &m_nCommandType,        ::getCppuType(reinterpret_cast< sal_Int32*>(NULL)));
-    registerProperty(PROPERTY_ACTIVECOMMAND,        PROPERTY_ID_ACTIVECOMMAND,          nRBT,                           &m_aActiveCommand,      ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
+    registerMayBeVoidProperty(PROPERTY_ACTIVE_CONNECTION,PROPERTY_ID_ACTIVE_CONNECTION, PropertyAttribute::MAYBEVOID|PropertyAttribute::TRANSIENT|PropertyAttribute::BOUND, &m_aActiveConnection,   ::getCppuType(static_cast< Reference< XConnection >* >(0)));
+    registerProperty(PROPERTY_DATASOURCENAME,       PROPERTY_ID_DATASOURCENAME,         PropertyAttribute::BOUND,       &m_aDataSourceName,     ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(PROPERTY_COMMAND,              PROPERTY_ID_COMMAND,                PropertyAttribute::BOUND,       &m_aCommand,            ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(PROPERTY_COMMAND_TYPE,         PROPERTY_ID_COMMAND_TYPE,           PropertyAttribute::BOUND,       &m_nCommandType,        ::getCppuType(static_cast< sal_Int32*>(0)));
+    registerProperty(PROPERTY_ACTIVECOMMAND,        PROPERTY_ID_ACTIVECOMMAND,          nRBT,                           &m_aActiveCommand,      ::getCppuType(static_cast< ::rtl::OUString*>(0)));
     registerProperty(PROPERTY_IGNORERESULT,         PROPERTY_ID_IGNORERESULT,           PropertyAttribute::BOUND,       &m_bIgnoreResult,       ::getBooleanCppuType());
-    registerProperty(PROPERTY_FILTER,               PROPERTY_ID_FILTER,                 PropertyAttribute::BOUND,       &m_aFilter,             ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(PROPERTY_HAVING_CLAUSE,        PROPERTY_ID_HAVING_CLAUSE,          PropertyAttribute::BOUND,       &m_aHavingClause,       ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(PROPERTY_GROUP_BY,             PROPERTY_ID_GROUP_BY,               PropertyAttribute::BOUND,       &m_aGroupBy,            ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
+    registerProperty(PROPERTY_FILTER,               PROPERTY_ID_FILTER,                 PropertyAttribute::BOUND,       &m_aFilter,             ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(PROPERTY_HAVING_CLAUSE,        PROPERTY_ID_HAVING_CLAUSE,          PropertyAttribute::BOUND,       &m_aHavingClause,       ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(PROPERTY_GROUP_BY,             PROPERTY_ID_GROUP_BY,               PropertyAttribute::BOUND,       &m_aGroupBy,            ::getCppuType(static_cast< ::rtl::OUString*>(0)));
     registerProperty(PROPERTY_APPLYFILTER,          PROPERTY_ID_APPLYFILTER,            PropertyAttribute::BOUND,       &m_bApplyFilter,        ::getBooleanCppuType());
-    registerProperty(PROPERTY_ORDER,                PROPERTY_ID_ORDER,                  PropertyAttribute::BOUND,       &m_aOrder,              ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(PROPERTY_PRIVILEGES,           PROPERTY_ID_PRIVILEGES,             nRT,                            &m_nPrivileges,         ::getCppuType(reinterpret_cast< sal_Int32*>(NULL)));
+    registerProperty(PROPERTY_ORDER,                PROPERTY_ID_ORDER,                  PropertyAttribute::BOUND,       &m_aOrder,              ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(PROPERTY_PRIVILEGES,           PROPERTY_ID_PRIVILEGES,             nRT,                            &m_nPrivileges,         ::getCppuType(static_cast< sal_Int32*>(0)));
     registerProperty(PROPERTY_ISMODIFIED,           PROPERTY_ID_ISMODIFIED,             nBT,                            &m_bModified,           ::getBooleanCppuType());
     registerProperty(PROPERTY_ISNEW,                PROPERTY_ID_ISNEW,                  nRBT,                           &m_bNew,                ::getBooleanCppuType());
-    registerProperty(PROPERTY_SINGLESELECTQUERYCOMPOSER,PROPERTY_ID_SINGLESELECTQUERYCOMPOSER,  nRT,                    &m_xComposer,   ::getCppuType(reinterpret_cast< Reference< XSingleSelectQueryComposer >* >(NULL)));
+    registerProperty(PROPERTY_SINGLESELECTQUERYCOMPOSER,PROPERTY_ID_SINGLESELECTQUERYCOMPOSER,  nRT,                    &m_xComposer,   ::getCppuType(static_cast< Reference< XSingleSelectQueryComposer >* >(0)));
 
     // sdbcx.ResultSet Properties
     registerProperty(PROPERTY_ISBOOKMARKABLE,       PROPERTY_ID_ISBOOKMARKABLE,         nRT,                            &m_bIsBookmarkable,      ::getBooleanCppuType());
     registerProperty(PROPERTY_CANUPDATEINSERTEDROWS,PROPERTY_ID_CANUPDATEINSERTEDROWS,  nRT,                            &m_bCanUpdateInsertedRows,      ::getBooleanCppuType());
     // sdbc.ResultSet Properties
-    registerProperty(PROPERTY_RESULTSETCONCURRENCY, PROPERTY_ID_RESULTSETCONCURRENCY,   PropertyAttribute::TRANSIENT,   &m_nResultSetConcurrency,::getCppuType(reinterpret_cast< sal_Int32*>(NULL)));
-    registerProperty(PROPERTY_RESULTSETTYPE,        PROPERTY_ID_RESULTSETTYPE,          PropertyAttribute::TRANSIENT,   &m_nResultSetType,      ::getCppuType(reinterpret_cast< sal_Int32*>(NULL)));
-    registerProperty(PROPERTY_FETCHDIRECTION,       PROPERTY_ID_FETCHDIRECTION,         PropertyAttribute::TRANSIENT,   &m_nFetchDirection,     ::getCppuType(reinterpret_cast< sal_Int32*>(NULL)));
-    registerProperty(PROPERTY_FETCHSIZE,            PROPERTY_ID_FETCHSIZE,              PropertyAttribute::TRANSIENT,   &m_nFetchSize,          ::getCppuType(reinterpret_cast< sal_Int32*>(NULL)));
+    registerProperty(PROPERTY_RESULTSETCONCURRENCY, PROPERTY_ID_RESULTSETCONCURRENCY,   PropertyAttribute::TRANSIENT,   &m_nResultSetConcurrency,::getCppuType(static_cast< sal_Int32*>(0)));
+    registerProperty(PROPERTY_RESULTSETTYPE,        PROPERTY_ID_RESULTSETTYPE,          PropertyAttribute::TRANSIENT,   &m_nResultSetType,      ::getCppuType(static_cast< sal_Int32*>(0)));
+    registerProperty(PROPERTY_FETCHDIRECTION,       PROPERTY_ID_FETCHDIRECTION,         PropertyAttribute::TRANSIENT,   &m_nFetchDirection,     ::getCppuType(static_cast< sal_Int32*>(0)));
+    registerProperty(PROPERTY_FETCHSIZE,            PROPERTY_ID_FETCHSIZE,              PropertyAttribute::TRANSIENT,   &m_nFetchSize,          ::getCppuType(static_cast< sal_Int32*>(0)));
 
     // sdbc.RowSet Properties
-    registerProperty(PROPERTY_URL,                  PROPERTY_ID_URL,                    0,                              &m_aURL,                ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(PROPERTY_TRANSACTIONISOLATION, PROPERTY_ID_TRANSACTIONISOLATION,   PropertyAttribute::TRANSIENT,   &m_nTransactionIsolation,::getCppuType(reinterpret_cast< sal_Int32*>(NULL)));
-    registerMayBeVoidProperty(PROPERTY_TYPEMAP,     PROPERTY_ID_TYPEMAP,                PropertyAttribute::MAYBEVOID|PropertyAttribute::TRANSIENT,  &m_aTypeMap,            ::getCppuType(reinterpret_cast< Reference< XNameAccess >* >(NULL)));
+    registerProperty(PROPERTY_URL,                  PROPERTY_ID_URL,                    0,                              &m_aURL,                ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(PROPERTY_TRANSACTIONISOLATION, PROPERTY_ID_TRANSACTIONISOLATION,   PropertyAttribute::TRANSIENT,   &m_nTransactionIsolation,::getCppuType(static_cast< sal_Int32*>(0)));
+    registerMayBeVoidProperty(PROPERTY_TYPEMAP,     PROPERTY_ID_TYPEMAP,                PropertyAttribute::MAYBEVOID|PropertyAttribute::TRANSIENT,  &m_aTypeMap,            ::getCppuType(static_cast< Reference< XNameAccess >* >(0)));
     registerProperty(PROPERTY_ESCAPE_PROCESSING,PROPERTY_ID_ESCAPE_PROCESSING,  PropertyAttribute::BOUND,       &m_bUseEscapeProcessing,::getBooleanCppuType()  );
-    registerProperty(PROPERTY_QUERYTIMEOUT,         PROPERTY_ID_QUERYTIMEOUT,           PropertyAttribute::TRANSIENT,   &m_nQueryTimeOut,       ::getCppuType(reinterpret_cast< sal_Int32*>(NULL)));
-    registerProperty(PROPERTY_MAXFIELDSIZE,         PROPERTY_ID_MAXFIELDSIZE,           PropertyAttribute::TRANSIENT,   &m_nMaxFieldSize,       ::getCppuType(reinterpret_cast< sal_Int32*>(NULL)));
-    registerProperty(PROPERTY_MAXROWS,              PROPERTY_ID_MAXROWS,                0,                              &m_nMaxRows,            ::getCppuType(reinterpret_cast< sal_Int32*>(NULL)) );
-    registerProperty(PROPERTY_USER,                 PROPERTY_ID_USER,                   PropertyAttribute::TRANSIENT,   &m_aUser,               ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(PROPERTY_PASSWORD,             PROPERTY_ID_PASSWORD,               PropertyAttribute::TRANSIENT,   &m_aPassword,           ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-
-    registerProperty(PROPERTY_UPDATE_CATALOGNAME,   PROPERTY_ID_UPDATE_CATALOGNAME,     PropertyAttribute::BOUND,       &m_aUpdateCatalogName,  ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(PROPERTY_UPDATE_SCHEMANAME,    PROPERTY_ID_UPDATE_SCHEMANAME,      PropertyAttribute::BOUND,       &m_aUpdateSchemaName,   ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(PROPERTY_UPDATE_TABLENAME,     PROPERTY_ID_UPDATE_TABLENAME,       PropertyAttribute::BOUND,       &m_aUpdateTableName,    ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
+    registerProperty(PROPERTY_QUERYTIMEOUT,         PROPERTY_ID_QUERYTIMEOUT,           PropertyAttribute::TRANSIENT,   &m_nQueryTimeOut,       ::getCppuType(static_cast< sal_Int32*>(0)));
+    registerProperty(PROPERTY_MAXFIELDSIZE,         PROPERTY_ID_MAXFIELDSIZE,           PropertyAttribute::TRANSIENT,   &m_nMaxFieldSize,       ::getCppuType(static_cast< sal_Int32*>(0)));
+    registerProperty(PROPERTY_MAXROWS,              PROPERTY_ID_MAXROWS,                0,                              &m_nMaxRows,            ::getCppuType(static_cast< sal_Int32*>(0)) );
+    registerProperty(PROPERTY_USER,                 PROPERTY_ID_USER,                   PropertyAttribute::TRANSIENT,   &m_aUser,               ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(PROPERTY_PASSWORD,             PROPERTY_ID_PASSWORD,               PropertyAttribute::TRANSIENT,   &m_aPassword,           ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+
+    registerProperty(PROPERTY_UPDATE_CATALOGNAME,   PROPERTY_ID_UPDATE_CATALOGNAME,     PropertyAttribute::BOUND,       &m_aUpdateCatalogName,  ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(PROPERTY_UPDATE_SCHEMANAME,    PROPERTY_ID_UPDATE_SCHEMANAME,      PropertyAttribute::BOUND,       &m_aUpdateSchemaName,   ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(PROPERTY_UPDATE_TABLENAME,     PROPERTY_ID_UPDATE_TABLENAME,       PropertyAttribute::BOUND,       &m_aUpdateTableName,    ::getCppuType(static_cast< ::rtl::OUString*>(0)));
 
     // ???
     registerProperty(PROPERTY_CHANGE_NOTIFICATION_ENABLED, PROPERTY_ID_PROPCHANGE_NOTIFY, PropertyAttribute::BOUND,     &m_bPropChangeNotifyEnabled, ::getBooleanCppuType());
@@ -2806,11 +2806,11 @@
     sal_Int32 nRT   = PropertyAttribute::READONLY   | PropertyAttribute::TRANSIENT;
 
     // sdb.RowSet Properties
-    registerMayBeVoidProperty(PROPERTY_ACTIVE_CONNECTION,PROPERTY_ID_ACTIVE_CONNECTION, PropertyAttribute::MAYBEVOID|PropertyAttribute::READONLY,   &rParent.m_aActiveConnection,   ::getCppuType(reinterpret_cast< Reference< XConnection >* >(NULL)));
-    registerProperty(PROPERTY_RESULTSETCONCURRENCY, PROPERTY_ID_RESULTSETCONCURRENCY,   PropertyAttribute::READONLY,    &m_nResultSetConcurrency,::getCppuType(reinterpret_cast< sal_Int32*>(NULL)));
-    registerProperty(PROPERTY_RESULTSETTYPE,        PROPERTY_ID_RESULTSETTYPE,          PropertyAttribute::READONLY,    &m_nResultSetType,      ::getCppuType(reinterpret_cast< sal_Int32*>(NULL)));
-    registerProperty(PROPERTY_FETCHDIRECTION,       PROPERTY_ID_FETCHDIRECTION,         PropertyAttribute::TRANSIENT,   &m_nFetchDirection,     ::getCppuType(reinterpret_cast< sal_Int32*>(NULL)));
-    registerProperty(PROPERTY_FETCHSIZE,            PROPERTY_ID_FETCHSIZE,              PropertyAttribute::TRANSIENT,   &m_nFetchSize,          ::getCppuType(reinterpret_cast< sal_Int32*>(NULL)));
+    registerMayBeVoidProperty(PROPERTY_ACTIVE_CONNECTION,PROPERTY_ID_ACTIVE_CONNECTION, PropertyAttribute::MAYBEVOID|PropertyAttribute::READONLY,   &rParent.m_aActiveConnection,   ::getCppuType(static_cast< Reference< XConnection >* >(0)));
+    registerProperty(PROPERTY_RESULTSETCONCURRENCY, PROPERTY_ID_RESULTSETCONCURRENCY,   PropertyAttribute::READONLY,    &m_nResultSetConcurrency,::getCppuType(static_cast< sal_Int32*>(0)));
+    registerProperty(PROPERTY_RESULTSETTYPE,        PROPERTY_ID_RESULTSETTYPE,          PropertyAttribute::READONLY,    &m_nResultSetType,      ::getCppuType(static_cast< sal_Int32*>(0)));
+    registerProperty(PROPERTY_FETCHDIRECTION,       PROPERTY_ID_FETCHDIRECTION,         PropertyAttribute::TRANSIENT,   &m_nFetchDirection,     ::getCppuType(static_cast< sal_Int32*>(0)));
+    registerProperty(PROPERTY_FETCHSIZE,            PROPERTY_ID_FETCHSIZE,              PropertyAttribute::TRANSIENT,   &m_nFetchSize,          ::getCppuType(static_cast< sal_Int32*>(0)));
     registerProperty(PROPERTY_ISBOOKMARKABLE,       PROPERTY_ID_ISBOOKMARKABLE,         nRT,                            &m_bIsBookmarkable,      ::getBooleanCppuType());
 }
 
