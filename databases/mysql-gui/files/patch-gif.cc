--- gif.cc.orig	Wed Apr 11 21:12:24 2001
+++ gif.cc	Mon Feb  3 03:46:27 2003
@@ -107,11 +107,11 @@
 		box(FL_NO_BOX);	end(); show();
 	}
 	~gif_window () { 
-		if (p && p->data) {
-			char** real_data = (char**)(p->data);
+		if (p && p->alloc_data) {
+			char** real_data = (char**)(p->alloc_data);
 			for (int i = 0; i < 3; i++) delete[] real_data[i];
 			delete[] real_data;
-			p->data = 0; delete p; p = 0;
+			p->alloc_data = 0; delete p; p = 0;
 		}
 		if (linelength) free((void*)linelength);  
 	}
