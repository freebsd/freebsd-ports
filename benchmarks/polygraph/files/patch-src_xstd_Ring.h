commit a1b938b85e2b9aabb95fb09b9f7137b27135ea72
Author: Alex Rousskov <rousskov@measurement-factory.com>
Date:   Thu Jan 7 08:20:34 2016 -0700

    lp:1380660: Make failed if gcc 4.9 is used.
    
    Merged POLY-43-lp1380660-make-failed-if-gcc-49-.

--- src/xstd/Ring.h.orig	2014-10-22 23:22:22 UTC
+++ src/xstd/Ring.h
@@ -19,6 +19,7 @@ class Ring: protected Array<Item> {
 
 		using Array<Item>::capacity;
 		using Array<Item>::size;
+		using Array<Item>::Value;
 
 		int count() const { return theInOff - theOutOff; }
 		bool empty() const { return theInOff <= theOutOff; }
