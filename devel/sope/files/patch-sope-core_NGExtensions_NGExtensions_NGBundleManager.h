--- sope-core/NGExtensions/NGExtensions/NGBundleManager.h.orig	2015-09-16 18:26:49 UTC
+++ sope-core/NGExtensions/NGExtensions/NGBundleManager.h
@@ -23,6 +23,7 @@
 #define __NGExtensions_NGBundleManager_H__
 
 #import <Foundation/NSObject.h>
+#define EXPOSE_NSBundle_IVARS
 #import <Foundation/NSBundle.h>
 #import <Foundation/NSMapTable.h>
 #include <NGExtensions/NGExtensionsDecls.h>
