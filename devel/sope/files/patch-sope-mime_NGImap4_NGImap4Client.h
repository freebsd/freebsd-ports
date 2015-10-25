--- sope-mime/NGImap4/NGImap4Client.h.orig	2015-09-16 18:26:50 UTC
+++ sope-mime/NGImap4/NGImap4Client.h
@@ -195,6 +195,14 @@ typedef enum {
   qualifierString:(NSString *)_qualString
   encoding:(NSString *)_encoding;
 
+/* Previously in Private category, but required by SoObjects/Mailer/SOGoMailBaseObject.m */
+
+- (NGHashMap *)processCommand:(NSString *)_command;
+- (NGHashMap *)processCommand:(NSString *)_command withTag:(BOOL)_tag;
+- (NGHashMap *)processCommand:(NSString *)_command withTag:(BOOL)_tag
+  withNotification:(BOOL)_notification;
+- (NGHashMap *)processCommand:(NSString *)_command logText:(NSString *)_txt;
+
 @end
 
 #endif /* __SOPE_NGImap4_NGImap4Client_H__ */
