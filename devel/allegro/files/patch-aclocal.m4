--- aclocal.m4.orig	Thu Feb  7 19:52:21 2002
+++ aclocal.m4	Thu Feb  7 19:52:45 2002
@@ -181,7 +181,7 @@
       LDFLAGS="$allegro_save_LDFLAGS"])
     if test $allegro_cv_support_export_dynamic = yes; then
       allegro_support_modules=yes
-      LIBS="-ldl $LIBS"
+      LIBS="$LIBS"
       LDFLAGS="-Wl,-export-dynamic $LDFLAGS"
     fi])
 fi
