--- src/FAL.cpp.orig	2017-12-31 02:15:18 UTC
+++ src/FAL.cpp
@@ -39,10 +39,10 @@
 	#define PTRACE_POKETEXT PT_WRITE_I
 #endif
 
-//#if defined BSD
-//	#define DKIOCGETBLOCKSIZE DIOCGSECTORSIZE	/* Get the sector size of the device in bytes */
-//	#define DKIOCGETBLOCKCOUNT DIOCGMEDIASIZE	/* Get media size in bytes */
-//#endif
+#if defined BSD
+	#define DKIOCGETBLOCKSIZE DIOCGSECTORSIZE	/* Get the sector size of the device in bytes */
+	#define DKIOCGETBLOCKCOUNT DIOCGMEDIASIZE	/* Get media size in bytes */
+#endif
 
 
 WX_DEFINE_OBJARRAY(ArrayOfNode);
@@ -208,7 +208,7 @@ bool FAL::OSDependedOpen(wxFileName& myfilename, FileA
 		myfilename.GetFullPath().Mid(5).ToLong(&a);
 		ProcessID=a;
 		RAMProcess=true;
-		if((ptrace(PTRACE_ATTACH, ProcessID, NULL, NULL)) < 0 ){
+		if((ptrace(PTRACE_ATTACH, ProcessID, NULL, 0)) < 0 ){
 			wxMessageBox( _("Process cannot open."),_("Error"), wxOK|wxICON_ERROR );
 			ProcessID=-1;
 			return false;
@@ -326,7 +326,7 @@ bool FAL::FALOpen(wxFileName& myfilename, FileAccessMo
 bool FAL::Close(){
 			#ifndef __WXMSW__
 			if( ProcessID >=0 )
-				return ((ptrace(PTRACE_DETACH, ProcessID, NULL, NULL)) >= 0 );
+				return ((ptrace(PTRACE_DETACH, ProcessID, NULL, 0)) >= 0 );
 			#endif
 			#ifdef __WXMSW__
 			if(IsWinDevice( the_file ) ){
@@ -521,7 +521,7 @@ bool FAL::Apply( void ){
 						long word=0;
 						//unsigned long *ptr = (unsigned long *) buffer;
 						while (rd < rd_size) {
-							word = ptrace(PTRACE_PEEKTEXT, ProcessID, reinterpret_cast<char*>(StartSector*BlockRWSize+rd), NULL);
+							word = ptrace(PTRACE_PEEKTEXT, ProcessID, reinterpret_cast<char*>(StartSector*BlockRWSize+rd), 0);
 							memcpy( bfr+rd , &word, 4);
 							rd += 4;
 							}
@@ -803,7 +803,7 @@ long FAL::ReadR( unsigned char* buffer, unsigned size,
 				//unsigned long *ptr = (unsigned long *) buffer;
 				#ifndef __WXMSW__
 				while (rd < rd_size) {
-					word = ptrace(PTRACE_PEEKTEXT, ProcessID, reinterpret_cast<char*>(StartSector*BlockRWSize+rd), NULL);
+					word = ptrace(PTRACE_PEEKTEXT, ProcessID, reinterpret_cast<char*>(StartSector*BlockRWSize+rd), 0);
 					memcpy( bfr+rd , &word, 4);
 					rd += 4;
 					}
