--- ../connectivity/source/drivers/mozab/mozillasrc/MNSInit.cxx.orig	Sat May 18 02:01:33 2002
+++ ../connectivity/source/drivers/mozab/mozillasrc/MNSInit.cxx	Sat May 18 02:02:18 2002
@@ -2,9 +2,9 @@
  *
  *	$RCSfile: MNSInit.cxx,v $
  *
- *	$Revision: 1.4 $
+ *	$Revision: 1.5 $
  *
- *	last change: $Author: dkenny $ $Date: 2001/12/12 15:32:45 $
+ *	last change: $Author: fs $ $Date: 2002/05/17 12:08:41 $
  *
  *	The Contents of this file are made available subject to the terms of
  *	either of the following licenses
@@ -269,7 +269,7 @@
 #ifdef _DEBUG
 				nsCAutoString temp1;
 				temp1.AssignWithConversion( pUsedProfile );
-				OSL_TRACE("Profile Name: %s\n", NS_STATIC_CAST(const char*, temp1));
+				OSL_TRACE("Profile Name: %s\n", NS_STATIC_CAST(const char*, temp1.get()));
 #endif
 				theProfile->SetCurrentProfile( pUsedProfile );
 
