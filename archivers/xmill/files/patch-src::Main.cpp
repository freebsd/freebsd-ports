--- src/Main.cpp.orig	Fri May  9 16:24:51 2003
+++ src/Main.cpp	Fri May  9 16:25:41 2003
@@ -599,7 +599,7 @@
       return;
    }
 
-   if(output.CreateFile((no_output==0) ? destfile : "")==0)
+   if(output.CreateFile((no_output==0) ? destfile : (char *)"")==0)
    {
       Error("Could not create output file '");
       ErrorCont(destfile);
@@ -816,7 +816,7 @@
 
    globallabeldict.Init();
 
-   if(output.CreateFile((no_output==0) ? destfile : "")==0)
+   if(output.CreateFile((no_output==0) ? destfile : (char *)"")==0)
    {
       Error("Could not create output file '");
       ErrorCont(destfile);
@@ -905,4 +905,4 @@
 {
    return malloc(size);
 }
-*/
\ No newline at end of file
+*/
