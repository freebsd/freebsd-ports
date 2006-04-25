--- functions.h.orig	Tue Jan 11 18:56:41 2005
+++ functions.h	Tue Apr 25 17:25:29 2006
@@ -41,7 +41,7 @@
 NSString *systemBundlePath(void);
 NSString *userBundlePath(void);
 
-void fillPopup(id popupButton, NSString *folder, NSString *ext, int removeIx );
+void fillPopup(NSPopUpButton *popupButton, NSString *folder, NSString *ext, int removeIx );
 NSDictionary *dictionaryFromFolder(NSString *folder, NSString *name);
 
 float convertToUnit(float value);
