--- Bundles/OSS/OSSPreference.h.orig	2006-03-18 05:13:52.000000000 +0100
+++ Bundles/OSS/OSSPreference.h	2008-06-16 21:14:16.000000000 +0200
@@ -24,6 +24,8 @@
 #define OSSPREFERENCE_H
 
 #import <Cynthiune/Preference.h>
+#import <Foundation/NSDictionary.h>
+#import <Foundation/NSArchiver.h>
 
 @class NSBox;
 @class NSWindow;
