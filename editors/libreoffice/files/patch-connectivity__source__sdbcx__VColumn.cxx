--- ./connectivity/source/sdbcx/VColumn.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/sdbcx/VColumn.cxx	2012-07-18 13:07:09.000000000 -0400
@@ -166,13 +166,13 @@
 
     sal_Int32 nAttrib = isNew() ? 0 : PropertyAttribute::READONLY;
 
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_TYPENAME),            PROPERTY_ID_TYPENAME,           nAttrib,&m_TypeName,        ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_DESCRIPTION),     PROPERTY_ID_DESCRIPTION,        nAttrib,&m_Description,     ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_DEFAULTVALUE),        PROPERTY_ID_DEFAULTVALUE,       nAttrib,&m_DefaultValue,    ::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_PRECISION),       PROPERTY_ID_PRECISION,          nAttrib,&m_Precision,       ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_TYPE),                PROPERTY_ID_TYPE,               nAttrib,&m_Type,            ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_SCALE),           PROPERTY_ID_SCALE,              nAttrib,&m_Scale,           ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_ISNULLABLE),      PROPERTY_ID_ISNULLABLE,         nAttrib,&m_IsNullable,      ::getCppuType(reinterpret_cast<sal_Int32*>(NULL)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_TYPENAME),            PROPERTY_ID_TYPENAME,           nAttrib,&m_TypeName,        ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_DESCRIPTION),     PROPERTY_ID_DESCRIPTION,        nAttrib,&m_Description,     ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_DEFAULTVALUE),        PROPERTY_ID_DEFAULTVALUE,       nAttrib,&m_DefaultValue,    ::getCppuType(static_cast< ::rtl::OUString*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_PRECISION),       PROPERTY_ID_PRECISION,          nAttrib,&m_Precision,       ::getCppuType(static_cast<sal_Int32*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_TYPE),                PROPERTY_ID_TYPE,               nAttrib,&m_Type,            ::getCppuType(static_cast<sal_Int32*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_SCALE),           PROPERTY_ID_SCALE,              nAttrib,&m_Scale,           ::getCppuType(static_cast<sal_Int32*>(0)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_ISNULLABLE),      PROPERTY_ID_ISNULLABLE,         nAttrib,&m_IsNullable,      ::getCppuType(static_cast<sal_Int32*>(0)));
     registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_ISAUTOINCREMENT), PROPERTY_ID_ISAUTOINCREMENT,    nAttrib,&m_IsAutoIncrement, ::getBooleanCppuType());
     registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_ISROWVERSION),        PROPERTY_ID_ISROWVERSION,       nAttrib,&m_IsRowVersion,    ::getBooleanCppuType());
     registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_ISCURRENCY),      PROPERTY_ID_ISCURRENCY,         nAttrib,&m_IsCurrency,      ::getBooleanCppuType());
