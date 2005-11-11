--- src/hip.cpp	Wed Aug 25 11:41:56 2004
+++ src/hip.cpp	Mon Mar 14 11:54:38 2005
@@ -85,12 +85,10 @@
 				  word *buf) = 0;
 	virtual void ReadDspSram(USHORT board, USHORT addr, USHORT length,
 				 word *buf) = 0;
-#ifndef __FreeBSD__
 	virtual void WriteIic(USHORT board, USHORT addr, USHORT length, 
 				  word *buf) = 0;
 	virtual void ReadIic(USHORT board, USHORT addr, USHORT length,
 				 word *buf) = 0;
-#endif
 	virtual void EeRead(USHORT board, USHORT addr, USHORT length,
 				 word *buf) = 0;
 	virtual void SetPip(USHORT board, char enables) = 0;
@@ -295,7 +293,6 @@
 	d->ReadDspSram(board, addr, length, buf);
 }
 
-#ifndef __FreeBSD__
 /*-------------------------------------------------------------------------*\
 	
     FUNCTION.: Hip::WriteIic
@@ -334,8 +331,6 @@
 	d->ReadIic(board, addr, length, buf);
 }
 
-#endif
-
 /*-------------------------------------------------------------------------*\
 	
     FUNCTION.: Hip::EeRead
@@ -945,7 +940,6 @@
 	GenericLeaveCriticalSection(&HipSect);
 }
 
-#ifndef __FreeBSD__
 /*-------------------------------------------------------------------------*\
 	
     FUNCTION.: HipDataPCI::WriteIic
@@ -1011,7 +1005,6 @@
 
 	GenericLeaveCriticalSection(&HipSect);
 }
-#endif
 
 /*-------------------------------------------------------------------------*\
 	
