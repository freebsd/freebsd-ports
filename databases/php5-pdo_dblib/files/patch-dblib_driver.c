--- dblib_driver.c.orig	2013-08-12 16:49:42.000000000 +0200
+++ dblib_driver.c	2013-08-12 16:50:11.000000000 +0200
@@ -274,9 +274,13 @@
 		,{"5.0",DBVERSION_70} /* FIXME: This does not work with Sybase, but environ will */
 		,{"6.0",DBVERSION_70}
 		,{"7.0",DBVERSION_70}
+#ifdef DBVERSION_71
 		,{"7.1",DBVERSION_71}
+#endif
+#ifdef DBVERSION_72
 		,{"7.2",DBVERSION_72}
 		,{"8.0",DBVERSION_72}
+#endif
 		,{"10.0",DBVERSION_100}
 		,{"auto",0} /* Only works with FreeTDS. Other drivers will bork */
 		
