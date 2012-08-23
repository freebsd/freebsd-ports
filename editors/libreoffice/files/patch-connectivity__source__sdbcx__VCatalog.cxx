--- ./connectivity/source/sdbcx/VCatalog.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/sdbcx/VCatalog.cxx	2012-07-18 13:18:57.000000000 -0400
@@ -230,7 +230,7 @@
 void ODescriptor::construct()
 {
     sal_Int32 nAttrib = isNew() ? 0 : ::com::sun::star::beans::PropertyAttribute::READONLY;
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_NAME), PROPERTY_ID_NAME ,nAttrib,&m_Name,::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_NAME), PROPERTY_ID_NAME ,nAttrib,&m_Name,::getCppuType(static_cast< ::rtl::OUString*>(0)));
 }
 // -------------------------------------------------------------------------
 ODescriptor::~ODescriptor()
