--- ./mysqlc/source/mysqlc_propertyids.hxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./mysqlc/source/mysqlc_propertyids.hxx	2012-07-18 15:00:02.000000000 -0400
@@ -119,7 +119,7 @@
 
 //------------------------------------------------------------------------------
 #define DECL_PROP1IMPL(varname, type) \
-pProperties[nPos++] = Property(OPropertyMap::getPropMap().getNameByIndex(PROPERTY_ID_##varname), PROPERTY_ID_##varname, ::getCppuType(reinterpret_cast< type*>(NULL)),
+pProperties[nPos++] = Property(OPropertyMap::getPropMap().getNameByIndex(PROPERTY_ID_##varname), PROPERTY_ID_##varname, ::getCppuType(static_cast< type*>(0)),
 //------------------------------------------------------------------------------
 #define DECL_PROP0(varname, type)   \
     DECL_PROP1IMPL(varname, type) 0)
