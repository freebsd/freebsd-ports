--- EOAccess/EOUtilities.m.orig	2007-01-01 12:52:38.000000000 +0100
+++ EOAccess/EOUtilities.m	2008-06-16 03:59:08.000000000 +0200
@@ -76,7 +76,9 @@
 #include "EOPrivate.h"
 
 NSString *EOMoreThanOneException = @"EOMoreThanOneException";
+#ifndef MAC_OS_X_VERSION_10_5
 NSString *NSObjectNotAvailableException = @"NSObjectNotAvailableException";
+#endif
 
 
 @implementation EOEditingContext (EOUtilities)
