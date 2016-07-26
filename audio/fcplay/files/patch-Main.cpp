--- Main.cpp.orig	1997-03-03 21:47:00 UTC
+++ Main.cpp
@@ -1,8 +1,11 @@
-#include <fstream.h>
+#include <fstream>
 #include <limits.h>
 #include <signal.h>
 #include <stdlib.h>
-#include <string.h>
+#include <cstring>
+#include <iostream>
+using namespace std;
+#include <new>
 
 #include "FC.h"
 #include "MyTypes.h"
@@ -95,11 +98,7 @@ int main(int argc, char *argv[])
     streampos fileLen = 0;
   
     // open binary input file stream at end of file
-#if defined(HAVE_IOS_BIN)
-    ifstream myIn( argv[inFileArgN], ios::in | ios::bin | ios::ate | ios::nocreate );
-#else
-    ifstream myIn( argv[inFileArgN], ios::in | ios::binary | ios::ate | ios::nocreate );
-#endif
+    ifstream myIn( argv[inFileArgN], ios::in | ios::binary | ios::ate );
 	// As a replacement for !is_open(), bad() and the NOT-operator don't seem
 	// to work on all systems.
 #if defined(DONT_HAVE_IS_OPEN)
@@ -119,20 +118,20 @@ int main(int argc, char *argv[])
     fileLen = (udword)myIn.tellg();
 #endif
 	fileLen = myIn.tellg();
-	buffer = new ubyte[fileLen+extraFileBufLen];
+	buffer = new(std::nothrow) ubyte[(long int)fileLen+extraFileBufLen];
 	
 	myIn.seekg(0,ios::beg);
 	cout << "Loading" << flush;
 	streampos restFileLen = fileLen;
 	while ( restFileLen > INT_MAX )
     {
-        myIn.read( buffer + (fileLen - restFileLen), INT_MAX );
+        myIn.read( (char*)buffer + (fileLen - restFileLen), INT_MAX );
         restFileLen -= INT_MAX;
         cout << "." << flush;
 	}
 	if ( restFileLen > 0 )
     {
-        myIn.read( buffer + (fileLen - restFileLen), restFileLen );
+        myIn.read( (char*)buffer + (fileLen - restFileLen), restFileLen );
         cout << "." << flush;
 	}
 	cout << endl << flush;
@@ -147,7 +146,7 @@ int main(int argc, char *argv[])
     extern udword pcmFreq;
     pcmFreq = 44100;
 
-    ubyte* sampleBuffer = new ubyte[pcmFreq];
+    ubyte* sampleBuffer = new(std::nothrow) ubyte[pcmFreq];
 
     AudioConfig myAudioCfg;
     myAudioCfg.frequency = pcmFreq;
