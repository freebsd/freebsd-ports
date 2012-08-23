--- ./forms/source/inc/property.hxx.orig	2012-07-03 07:01:28.000000000 -0400
+++ ./forms/source/inc/property.hxx	2012-07-18 14:18:22.000000000 -0400
@@ -111,7 +111,7 @@
 
 //------------------------------------------------------------------------------
 #define DECL_PROP_IMPL(varname, type) \
-    *pProperties++ = com::sun::star::beans::Property(PROPERTY_##varname, PROPERTY_ID_##varname, ::getCppuType(reinterpret_cast< type* >(NULL)),
+    *pProperties++ = com::sun::star::beans::Property(PROPERTY_##varname, PROPERTY_ID_##varname, ::getCppuType(static_cast< type* >(0)),
 
 //------------------------------------------------------------------------------
 #define DECL_BOOL_PROP_IMPL(varname) \
@@ -119,7 +119,7 @@
 
 //------------------------------------------------------------------------------
 #define DECL_IFACE_PROP_IMPL(varname, type) \
-    *pProperties++ = com::sun::star::beans::Property(PROPERTY_##varname, PROPERTY_ID_##varname, ::getCppuType(reinterpret_cast< com::sun::star::uno::Reference< type >* >(NULL)),
+    *pProperties++ = com::sun::star::beans::Property(PROPERTY_##varname, PROPERTY_ID_##varname, ::getCppuType(static_cast< com::sun::star::uno::Reference< type >* >(0)),
 
 //------------------------------------------------------------------------------
 #define BEGIN_DESCRIBE_PROPERTIES( count, baseclass )   \
