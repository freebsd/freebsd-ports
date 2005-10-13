--- utility/refcnt_ptr.h.orig	Wed Oct 12 01:20:34 2005
+++ utility/refcnt_ptr.h	Wed Oct 12 01:20:40 2005
@@ -109,7 +109,7 @@
     refcnt_ptr(const refcnt_ptr<T2>& rhs) throw()
 	{
 	object = rhs.object;
-	refcnt = rhs.refCnt;
+	refCnt = rhs.refCnt;
 	increaseCount();
 	}
 
