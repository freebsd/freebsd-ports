--- macros/sdl.m4.orig	Sat Apr 22 11:10:23 2006
+++ macros/sdl.m4	Sat Apr 22 11:03:46 2006
@@ -59,8 +59,8 @@
         ac_cv_path_sdl_incl=$i/SDL/include
         break
       fi
-      if test -f $i/include/SDL/SDL.h; then
-        ac_cv_path_sdl_incl=$i/include/SDL
+      if test -f $i/include/SDL11/SDL.h; then
+        ac_cv_path_sdl_incl=$i/include/SDL11
         break
       fi
     done
@@ -94,17 +94,17 @@
 
   SDL_LIBS=""
   if test x"${ac_cv_path_sdl_lib}" = x ; then
-    AC_CHECK_LIB(SDL, SDL_Init, [ac_cv_path_sdl_lib="-lSDL"],[
+    AC_CHECK_LIB(SDL-1.1, SDL_Init, [ac_cv_path_sdl_lib="-lSDL-1.1"],[
       AC_MSG_CHECKING([for SDL library])
       liblist="${prefix}/lib64 ${prefix}/lib /usr/lib64 /usr/lib /usr/pkg/lib /sw/lib /usr/local/lib /home/latest/lib /opt/lib.. ../.."
       for i in $liblist; do
-        if test -f $i/libSDL.a -o -f $i/libSDl.so; then
+        if test -f $i/libSDL-1.1.a -o -f $i/libSDL-1.1.so; then
           if test x"$i" != x"/usr/lib"; then
-            ac_cv_path_sdl_lib="-L$i -lSDL"
+            ac_cv_path_sdl_lib="-L$i -lSDL-1.1"
             AC_MSG_RESULT(${ac_cv_path_sdl_lib})
             break
           else
-            ac_cv_path_sdl_lib="-lSDL"
+            ac_cv_path_sdl_lib="-lSDL-1.1"
             AC_MSG_RESULT([yes])
 	    has_sdl=yes
             break
