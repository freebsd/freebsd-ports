--- Game.cpp.orig	2008-11-11 16:54:38 UTC
+++ Game.cpp
@@ -1495,7 +1495,7 @@ void init( bool useDummyVideo=false )
     throw "Couldn't initialize SDL";
   }
   
-  if ( mkdir( (string(getenv("HOME"))+"/"USER_BASE_PATH).c_str(),
+  if ( mkdir( (string(getenv("HOME"))+"/" USER_BASE_PATH).c_str(),
 	      0755)==0 ) {
     printf("created user dir\n");
   } else if ( errno==EEXIST ){
