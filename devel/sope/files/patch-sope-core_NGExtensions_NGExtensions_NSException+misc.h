--- sope-core/NGExtensions/NGExtensions/NSException+misc.h.orig	2015-09-16 18:26:50 UTC
+++ sope-core/NGExtensions/NGExtensions/NSException+misc.h
@@ -22,6 +22,7 @@
 #ifndef __NGExtensions_NSException_misc_H__
 #define __NGExtensions_NSException_misc_H__
 
+#define EXPOSE_NSException_IVARS
 #import <Foundation/NSException.h>
 #import <Foundation/NSLock.h>
 
