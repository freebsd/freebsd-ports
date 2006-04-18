--- ext/ming/mingc/swfmovie.c~	Sun Oct 31 22:52:10 2004
+++ ext/ming/mingc/swfmovie.c	Wed Apr 12 23:42:58 2006
@@ -228,7 +228,7 @@
     level = NUM2INT(lobj);
 
   Data_Get_Struct(self, struct RSWFMovie, m);
-  len = SWFMovie_output(m->this, simpleOutputMethod, NULL, level);
+  len = SWFMovie_output(m->this, simpleOutputMethod, NULL/*, level*/);
   
   return INT2NUM(len);
 }
@@ -249,7 +249,7 @@
     level = NUM2INT(lobj);
 
   Data_Get_Struct(self, struct RSWFMovie, m);
-  count = SWFMovie_save(m->this, STR2CSTR(s), level);
+  count = SWFMovie_save(m->this, STR2CSTR(s)/*, level*/);
 
   return INT2NUM(count);
 }
