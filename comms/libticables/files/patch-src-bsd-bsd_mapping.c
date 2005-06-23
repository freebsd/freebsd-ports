--- src/bsd/bsd_mapping.c.orig	Mon May 30 14:01:58 2005
+++ src/bsd/bsd_mapping.c	Mon May 30 14:09:38 2005
@@ -74,9 +74,7 @@
 		break;
 
 	case LINK_AVR:
-		if(resources & IO_API) {
-			*method |= IOM_API | IOM_OK;	
-		}
+		printl1(2, "AVR link support has been removed !\n");
 		break;
 
 	case LINK_SER:
@@ -114,6 +112,7 @@
 
 	case LINK_TIE:
 	case LINK_VTI:
+	case LINK_VTL:
  		*method |= IOM_API | IOM_OK;
 		break;
 
@@ -212,7 +211,10 @@
 	ret = bsd_map_io((TicableMethod)method, port);
 	if(ret)
 		return ret;
-	
+
+	// set fields to default values
+	nul_register_cable(lc);
+
 	// set the link cable
 	printl1(0, _("registering cable...\n"));
     	switch (type) {
@@ -242,16 +244,6 @@
 			ser_register_cable_1(lc);
 		else if(method & IOM_IOCTL)
 			ser_register_cable_2(lc);
-		break;
-
-    	case LINK_AVR:
-      		if ((port != SERIAL_PORT_1) &&
-	  		(port != SERIAL_PORT_2) &&
-	  		(port != SERIAL_PORT_3) &&
-	  		(port != SERIAL_PORT_4) && (port != USER_PORT))
-		return ERR_INVALID_PORT;
-
-		avr_register_cable(lc);
 		break;
 
     	case LINK_VTL:
