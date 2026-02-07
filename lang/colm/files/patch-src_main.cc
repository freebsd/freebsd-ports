- use cc as compiler

--- src/main.cc.orig	2022-11-25 08:45:12 UTC
+++ src/main.cc
@@ -446,7 +446,7 @@ void compileOutput()
 {
 	const char *compiler = getenv( "CC" );
 	if ( compiler == 0 )
-		compiler = "gcc";
+		compiler = "cc";
 
 	const char *cflags = getenv( "CFLAGS" );
 	if ( cflags == 0 )
