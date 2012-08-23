--- ./connectivity/source/drivers/ado/AUser.cxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/drivers/ado/AUser.cxx	2012-07-18 14:51:51.000000000 -0400
@@ -145,7 +145,7 @@
 void OUserExtend::construct()
 {
     OUser_TYPEDEF::construct();
-    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_PASSWORD),    PROPERTY_ID_PASSWORD,0,&m_Password,::getCppuType(reinterpret_cast< ::rtl::OUString*>(NULL)));
+    registerProperty(OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_PASSWORD),    PROPERTY_ID_PASSWORD,0,&m_Password,::getCppuType(static_cast< ::rtl::OUString*>(0)));
 }
 // -----------------------------------------------------------------------------
 cppu::IPropertyArrayHelper* OUserExtend::createArrayHelper() const
