--- ifdtest.c.orig	2001-04-17 18:49:02.000000000 +0200
+++ ifdtest.c	2011-03-19 13:25:35.000000000 +0100
@@ -1,6 +1,5 @@
 #include <stdio.h>
 #include <winscard.h>
-#include <configfile.h>
 #include <stdlib.h>  
 #include "commands.h"
 #include <string.h>
@@ -21,13 +20,13 @@
 UCHAR value[300];
 struct ReaderContext *rContext;
 SCARD_IO_REQUEST sSendPci, sRecvPci;
-PSCARD_READERSTATE_A rgReaderStates[1];
+SCARD_READERSTATE* rgReaderStates[1];
 DWORD dwReaderLen, dwState, dwProt, dwAtrLen;
 DWORD dwSendLength, dwRecvLength, dwPref, dwReaders;
-LPSTR pcReaders, mszReaders;
+LPTSTR pcReaders, mszReaders;
 BYTE pbAtr[MAX_ATR_SIZE];
 BYTE s[300], r[300];
-LPCSTR mszGroups;
+LPCTSTR mszGroups;
 LONG rv;
 DWORD state;
 DWORD protocol;
@@ -110,18 +109,12 @@
 }
 if( outfile != NULL) fp = fopen(outfile,"w");
 else fp=NULL;
-	rv = SCardEstablishContext( SCARD_SCOPE_GLOBAL, pcHost, NULL, &hContext );
+	rv = SCardEstablishContext( SCARD_SCOPE_SYSTEM, pcHost, NULL, &hContext );
 	if ( rv != SCARD_S_SUCCESS ) {
 			myprintf("ERROR :: Resource Manager not running \n");
 			myprintf("Please start the resource manager and try again \n");
    		    return 1;
 	} 
-  rv = SCardSetTimeout(hContext,100);
-  if ( rv != SCARD_S_SUCCESS ) {
-    myprintf("ERROR :: Cannot Set timeout \n");
-    myprintf("PCSC ERROR: %s\n", pcsc_stringify_error(rv));
-    return -1;
-  }
   rv = SCardGetStatusChange( hContext, INFINITE, 0, 0 );
  
   if ( rv != SCARD_S_SUCCESS ) {
@@ -162,8 +155,8 @@
   } while ( iReader > p || iReader <= 0 );
 	
   rgReaderStates[0] =
- (PSCARD_READERSTATE_A)
-    malloc(sizeof(SCARD_READERSTATE_A));
+ (SCARD_READERSTATE*)
+    malloc(sizeof(SCARD_READERSTATE*));
 	strcpy(readerName,&mszReaders[iList[iReader]]);
 	printVersion(readerName);
   (rgReaderStates[0])->szReader       = strdup(readerName);
