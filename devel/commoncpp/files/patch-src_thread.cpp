--- src/thread.cpp	2010-10-31 17:58:07.000000000 -0700
+++ src/thread.cpp	2012-08-12 20:26:53.000000000 -0700
@@ -796,7 +796,7 @@
 cctid_t Thread::getId(void) const
 {
     if(!priv)
-        return (cctid_t)-1;
+	return (cctid_t)false;
 
     return priv->_tid;
 }
