
-L../libs/wine goes before -L/usr/local/lib.

--- tools/makedep.c.orig
+++ tools/makedep.c
@@ -3635,7 +3635,10 @@
 
         if (strarray_exists( &all_libs, "-lwine" ))
         {
+            struct strarray old_libs = all_libs;
+            all_libs = empty_strarray;
             strarray_add( &all_libs, strmake( "-L%s", top_obj_dir_path( make, "libs/wine" )));
+            strarray_addall(&all_libs, old_libs);
             if (ldrpath_local && ldrpath_install)
             {
                 program_installed = strmake( "%s-installed%s", make->programs.str[i], exe_ext );
