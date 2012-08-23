--- ./connectivity/source/drivers/hsqldb/HUser.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/drivers/hsqldb/HUser.cxx	2012-07-18 14:47:11.000000000 -0400
@@ -71,7 +71,7 @@
 typedef connectivity::sdbcx::OUser  OUser_TYPEDEF;
 void OUserExtend::construct()
 {
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_PASSWORD),    PROPERTY_ID_PASSWORD,0,&m_Password,::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_PASSWORD),    PROPERTY_ID_PASSWORD,0,&m_Password,::getCppuType(static_cast< ::rtl::OUString*>(0)));
 }
 // -----------------------------------------------------------------------------
 cppu::IPropertyArrayHelper* OUserExtend::createArrayHelper() const
