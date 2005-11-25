--- karbon/karbon_factory.cc.orig	Fri Nov 25 17:29:39 2005
+++ karbon/karbon_factory.cc	Fri Nov 25 17:29:59 2005
@@ -32,11 +32,7 @@
 
 #include <kdebug.h>
 
-
 KarbonResourceServer* KarbonFactory::s_rserver = 0;
-
-
-K_EXPORT_COMPONENT_FACTORY( libkarbonpart, KarbonFactory() )
 
 KInstance* KarbonFactory::s_instance = 0L;
 KAboutData* KarbonFactory::s_aboutData = 0L;
