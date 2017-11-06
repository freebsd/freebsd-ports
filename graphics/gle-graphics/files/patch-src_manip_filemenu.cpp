--- src/manip/filemenu.cpp.orig	2010-06-14 15:34:39 UTC
+++ src/manip/filemenu.cpp
@@ -404,10 +404,12 @@ void do_help(const char *k1, const char 
         gotoxy(1,1);
 	wprintf("Manip help on topic {%s},  sub topic {%s}",k1,k2);
         scr_menubg();
-        hfile = fopen(gledir(hfilename),"r");
+        string fname = gledir(hfilename);
+        hfilename = fname.c_str();
+        hfile = fopen(fname.c_str(),"r");
         if (hfile==NULL) {
 		gotoxy(1,3);
-		wprintf("Unable to open {%s} \n",gledir(hfilename));
+		wprintf("Unable to open {%s} \n",hfilename);
 		text_inkey();
 		return;
 	}
