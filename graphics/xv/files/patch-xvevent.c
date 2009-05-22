--- xvevent.c.orig	2009-05-22 07:21:18.000000000 +0200
+++ xvevent.c	2009-05-22 07:21:48.000000000 +0200
@@ -814,7 +814,7 @@
 	debkludge_offy = eHIGH-xwa.height+p_offy;
       }
 
-#if 0
+#if 1
       /* FIXME: if we want to do this, we first have to wait for a configure
        * notify to avoid a race condition because the location might be in-
        * correct if the window manager does placement after managing the window.
