--- src/thread.cpp	Wed Oct  4 19:16:54 2006
+++ src/thread.cpp	Wed Oct  4 19:17:17 2006
@@ -820,7 +820,7 @@
 cctid_t Thread::getId(void) const
 {
 	if(!priv)
-		return -1;
+		return false;
 
 	return priv->_tid;
 }
