--- dblib_driver.c.orig	2013-06-24 15:17:35.000000000 +0200
+++ dblib_driver.c	2013-06-24 15:20:43.000000000 +0200
@@ -274,9 +274,9 @@
 		,{"5.0",DBVERSION_70} /* FIXME: This does not work with Sybase, but environ will */
 		,{"6.0",DBVERSION_70}
 		,{"7.0",DBVERSION_70}
-		,{"7.1",DBVERSION_71}
-		,{"7.2",DBVERSION_72}
-		,{"8.0",DBVERSION_72}
+		,{"7.1",DBVERSION_80}
+		,{"7.2",DBVERSION_80}
+		,{"8.0",DBVERSION_80}
 		,{"10.0",DBVERSION_100}
 		,{"auto",0} /* Only works with FreeTDS. Other drivers will bork */
 		
