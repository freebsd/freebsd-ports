--- Lsystem/Lstring.cpp.orig	Wed Aug 16 18:54:26 2000
+++ Lsystem/Lstring.cpp	Wed Nov 19 22:05:11 2003
@@ -199,7 +199,7 @@
   
   if (sscanf(the_text.c_str(),"%f",&temp)==1)
     return temp;
-  return sqrt(-1);
+  return sqrtf(-1);
 
 }
 
@@ -329,13 +329,13 @@
   float param;
   int   conv,dummy;
   the_length=0;
-  if (the_pos==info_length()-1) return sqrt(-1);
-  if (bracketed_chars.find(the_text[the_pos])==string::npos) return sqrt(-1);
+  if (the_pos==info_length()-1) return sqrt(-1.0);
+  if (bracketed_chars.find(the_text[the_pos])==string::npos) return sqrt(-1.0);
 
   conv=sscanf(&(the_text.data()[the_pos+1]),"(%f)%n",&param,&the_length);
   if (conv==sscanf("","%n",&dummy)) {
     the_length=0;
-    return sqrt(-1);
+    return sqrt(-1.0);
   } else {
     return param;
   };
