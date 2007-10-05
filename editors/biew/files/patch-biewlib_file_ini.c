--- biewlib/file_ini.c.orig	2007-10-04 15:09:06.000000000 +0200
+++ biewlib/file_ini.c	2007-10-04 15:11:14.000000000 +0200
@@ -1295,7 +1295,7 @@
   void __HUGE__ *found;
   ini_cache __HUGE__ *it;
   ini_cache ic;
-  (const char *)ic.item = section;
+  ic.item = section;
   ic.flags = 0;
   if(!(found =la_Find((linearArray *)opening->cache,&ic,__full_compare_cache)))
   {
@@ -1325,7 +1325,7 @@
   {
     do_subsect:
       it = (ini_cache __HUGE__ *)found;
-      (const char *)ic.item = subsection;
+      ic.item = subsection;
       if(!(found=la_Find(it->v.leaf,&ic,__full_compare_cache)))
       {
         ic.item = PMalloc(strlen(subsection)+1);
@@ -1354,7 +1354,7 @@
       {
         do_item:
         it = (ini_cache __HUGE__ *)found;
-        (const char *)ic.item = item;
+        ic.item = item;
         ic.flags = IC_STRING;
         if(!(found=la_Find(it->v.leaf,&ic,__full_compare_cache)))
         {
@@ -1589,15 +1589,15 @@
           ini_cache ic;
           void __HUGE__ *found,__HUGE__ *foundi,__HUGE__ *foundv;
           ini_cache __HUGE__ *fi;
-          (const char *)ic.item = section;
+          ic.item = section;
           ic.flags = 0;
           if((found=la_Find(ini->cache,&ic,__full_compare_cache))!=NULL)
           {
-            (const char *)ic.item=subsection;
+            ic.item=subsection;
             fi = (ini_cache __HUGE__ *)found;
             if((foundi=la_Find(fi->v.leaf,&ic,__full_compare_cache))!=NULL)
             {
-               (const char *)ic.item = _item;
+               ic.item = _item;
                ic.flags = IC_STRING;
                fi = (ini_cache __HUGE__ *)foundi;
                if((foundv=la_Find(fi->v.leaf,&ic,__full_compare_cache))!=NULL)
