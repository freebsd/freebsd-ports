--- SpiralLoops.C.orig	2001-04-19 20:48:11 UTC
+++ SpiralLoops.C
@@ -308,7 +308,7 @@ int Loops::LinkPlugin()
         Run     = (Sample *(*)()) dlsym(handle, "Run__Fv");
         
                 
-        if ((error = dlerror()) != NULL)
+        if ((error = (char *)dlerror()) != NULL)
         {
         	cerr<<"Error linking to plugin:"<<endl;
 		    fputs(error, stderr);
@@ -467,7 +467,7 @@ inline void Loops::cb_Load_i(Fl_Button* 
 {
 	char *fn=fl_file_chooser("Load a Workspace", "*.lws", NULL);
 		
-	if (fn && fn!='\0')
+	if (fn && *fn!='\0')
 	{
 		ifstream inf(fn);
 		
@@ -504,7 +504,7 @@ inline void Loops::cb_Save_i(Fl_Button* 
 {
 	char *fn=fl_file_chooser("Save a Workspace", "*.lws", NULL);
 		
-	if (fn && fn!='\0')
+	if (fn && *fn!='\0')
 	{
 		ofstream of(fn);
 		
