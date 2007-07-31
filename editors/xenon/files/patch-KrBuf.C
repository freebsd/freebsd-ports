--- KrBuf.C.orig	2007-07-31 22:11:00.000000000 +0200
+++ KrBuf.C	2007-07-31 22:10:24.000000000 +0200
@@ -878,13 +878,13 @@
 void
 KrBuf::dump(bool printData)
 {
-    printf("KrBuf(0x%08x) size=%d\n", (int)this, _size);
+    printf("KrBuf(0x%08x) size=%d\n", (intptr_t)this, _size);
     
     int i, sp, pos = 0;
     MBuf* m = _mHead;
     while (m) {
 	printf("  MBuf(0x%08x) pos=%6d len=%3d data=[0x%08x..0x%08x]\n", 
-	    (int)m, pos, m->_len, (int)m->_data, (int)m->_data + m->_len - 1);
+	    (intptr_t)m, pos, m->_len, (intptr_t)m->_data, (intptr_t)m->_data + m->_len - 1);
 
 	if (printData) {	
 	    sp = (m->_data - m->_dat) % 0x20 + 1;
