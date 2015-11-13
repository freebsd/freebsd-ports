--- sope-gdl1/GDLAccess/EOSQLExpression.m.orig	2015-09-16 18:26:50 UTC
+++ sope-gdl1/GDLAccess/EOSQLExpression.m
@@ -39,6 +39,7 @@
 #include <EOControl/EONull.h>
 #include <EOControl/EOQualifier.h>
 #include <EOControl/EOSortOrdering.h>
+#import "NGExtensions/NSException+misc.h"
 
 #if LIB_FOUNDATION_LIBRARY
 #  include <extensions/DefaultScannerHandler.h>
