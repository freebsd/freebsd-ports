--- lavtools/divxdec.cpp.orig	Wed May 29 19:02:12 2002
+++ lavtools/divxdec.cpp	Wed May 29 20:08:34 2002
@@ -1284,7 +1284,7 @@
 	exit (1);
 }
 
-FILE* real_stdout;
+FILE real_stdout;
 
 int
 main (int argc, char **argv)
@@ -1309,8 +1309,8 @@
 	std::cout.rdbuf ( std::cerr.rdbuf () );
 	//
 	// 4. keep old stdout FILE, and use stderr in its place (for printf ("...") ; )
-	real_stdout = stdout ;
-	stdout = stderr;
+	real_stdout = *stdout ;
+	*stdout = *stderr;
 
 	displayGreeting();
 
@@ -1733,7 +1733,7 @@
 		if ( 0 == strcmp ( "-", filenameYUV ) )
 		{
 			//output.fdYUV = FD_STDOUT;
-			output.fdYUV = fileno ( real_stdout );
+			output.fdYUV = fileno ( &real_stdout );
 		}
 		else
 		{
@@ -2042,7 +2042,7 @@
 	freeAll ();
 	// reassign cout, stdout to their original values.
 	std::cout.rdbuf ( real_cout );
-	stdout = real_stdout;
+	*stdout = real_stdout;
 
 	mjpeg_info ( " " );
 	mjpeg_info ( "Done. %i frames", output.processedFrames );
