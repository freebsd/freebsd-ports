--- qterm/qtermtextline.cpp.orig	Sat Nov 13 15:26:48 2004
+++ qterm/qtermtextline.cpp	Sat Nov 13 15:27:41 2004
@@ -235,7 +235,7 @@
 
 	
 	if(index>=m_length)
-		return NULL;
+		return QCString();
 		
 	printf("index=%d len=%d m_length=%d\n", index, len, m_length);
 	
