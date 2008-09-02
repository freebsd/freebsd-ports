
--- include/log4cxx/xml/domconfigurator.h.orig	2008-08-12 23:36:20.000000000 +0200
+++ include/log4cxx/xml/domconfigurator.h	2008-08-12 23:36:28.000000000 +0200
@@ -208,7 +208,7 @@
 				spi::LoggerRepositoryPtr& repository);
 
 		protected:
-			String DOMConfigurator::subst(const String& value);
+			String subst(const String& value);
 
 		protected:
 			void * appenderBag;


