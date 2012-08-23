--- ./connectivity/source/inc/propertyids.hxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./connectivity/source/inc/propertyids.hxx	2012-07-18 13:36:46.000000000 -0400
@@ -75,7 +75,7 @@
 
 //------------------------------------------------------------------------------
 #define DECL_PROP1IMPL(varname, type) \
-pProperties[nPos++] = ::com::sun::star::beans::Property(::connectivity::OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_##varname), PROPERTY_ID_##varname, ::getCppuType(reinterpret_cast< type*>(NULL)),
+pProperties[nPos++] = ::com::sun::star::beans::Property(::connectivity::OMetaConnection::getPropMap().getNameByIndex(PROPERTY_ID_##varname), PROPERTY_ID_##varname, ::getCppuType(static_cast< type*>(0)),
 //------------------------------------------------------------------------------
 #define DECL_PROP0(varname, type)   \
     DECL_PROP1IMPL(varname, type) 0)
