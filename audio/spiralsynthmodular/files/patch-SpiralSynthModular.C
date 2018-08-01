SpiralSynthModular.C:1016:14: error: comparison between pointer and integer ('char *' and 'int')
        if (fn && fn!='\0')
                  ~~^ ~~~~

--- SpiralSynthModular.C.orig	2018-08-01 05:55:58 UTC
+++ SpiralSynthModular.C
@@ -1013,7 +1013,7 @@ inline void SynthModular::cb_Load_i(Fl_Button* o, void
 
 	char *fn=fl_file_chooser("Load a patch", "*.ssm", NULL);
 
-	if (fn && fn!='\0')
+	if (fn && *fn!='\0')
 	{
 		ifstream inf(fn);
 
@@ -1039,7 +1039,7 @@ inline void SynthModular::cb_Save_i(Fl_Button* o, void
 {
 	char *fn=fl_file_chooser("Save a patch", "*.ssm", NULL);
 
-	if (fn && fn!='\0')
+	if (fn && *fn!='\0')
 	{
 		ifstream ifl(fn);
 		if (ifl)
