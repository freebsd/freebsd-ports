--- GSFIFO.h.orig	2011-10-25 13:35:27.000000000 +0200
+++ GSFIFO.h	2011-11-04 10:22:40.000000000 +0100
@@ -25,7 +25,7 @@
 #import <Foundation/NSObject.h>
 
 @class NSArray;
-@class NSCondition;
+@class NSConditionLock;
 @class NSNumber;
 @class NSString;
 @class NSThread;
@@ -82,7 +82,7 @@
   uint16_t		timeout;
   uint64_t		fullCount;		// Total waits for full FIFO
   uint64_t		emptyCount;		// Total waits for empty FIFO
-  NSCondition		*condition;
+  NSConditionLock	*condition;
   NSString		*name;
   NSTimeInterval	getWaitTotal;		// Total time waiting for gets
   NSTimeInterval	putWaitTotal;		// Total time waiting for puts
