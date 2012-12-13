--- subcommander/ProjectWizard.cpp.orig	2008-11-15 20:42:38.000000000 +0900
+++ subcommander/ProjectWizard.cpp	2012-05-10 05:32:51.000000000 +0900
@@ -363,6 +363,8 @@
   sc::String wcPath = sc::String(field("WcPath").toString().utf8());
   sc::String wcUrl;
 
+  if ( wcPath.right(1) == "/" ) wcPath =  wcPath.left(wcPath.getByteCnt() - 1);
+
   svn::Client::getUrlFromPath( wcPath, wcUrl );
 
   setField( "TrunkUrl", QString::fromUtf8(wcUrl) );
