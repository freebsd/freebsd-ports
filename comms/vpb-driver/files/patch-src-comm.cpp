--- src/comm.cpp	Tue Apr 19 12:02:20 2005
+++ src/comm.cpp	Tue Oct  4 21:13:30 2005
@@ -841,6 +841,7 @@
 //	GenericEnterCriticalSection(&PutMessageSect);
 	mprintf("CommData::IicWrite addr:%x, len:%x, buf:%x %x %x %x \n",\
 		addr,length,buf[0],buf[1],buf[2],buf[3]);
+#ifndef __FreeBSD__
         switch (v->reg->model) 
 	{
 #ifndef WIN32
@@ -859,6 +860,9 @@
 		hip->WriteIic(board, addr, length, buf);	
 		break;
 	}
+#else
+	hip->WriteIic(board, addr, length, buf);	
+#endif
 	
 //	CheckForAssert(board);
 //	GenericLeaveCriticalSection(&PutMessageSect); //WIN32 has this in hipplx
@@ -886,6 +890,7 @@
 
 //	GenericEnterCriticalSection(&PutMessageSect);
 
+#ifndef __FreeBSD__
         switch  (v->reg->model) 
 	{
 #ifndef WIN32
@@ -903,6 +908,9 @@
 			hip->ReadIic(board, addr, length, buf);	
 			break;
 	}
+#else
+	hip->ReadIic(board, addr, length, buf);	
+#endif
 	
 //	CheckForAssert(board);
 //	GenericLeaveCriticalSection(&PutMessageSect);
