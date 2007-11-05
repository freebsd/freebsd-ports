--- fw/TInputContext.cpp.orig	2007-11-04 22:32:48.000000000 +0100
+++ fw/TInputContext.cpp	2007-11-04 22:33:03.000000000 +0100
@@ -75,5 +75,5 @@
 	xpoint.y = point.v;
 	
 	ICArg args[2] = { {XNSpotLocation, &xpoint}, {NULL, NULL} };
-	XSetICValues(fXIC, XNPreeditAttributes, args, NULL);
+	XSetICValues(fXIC, XNPreeditAttributes, args, (char *)NULL);
 }
