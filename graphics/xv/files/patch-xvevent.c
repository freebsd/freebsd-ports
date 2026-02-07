--- src/xvevent.c.orig	2023-07-17 01:25:42 UTC
+++ src/xvevent.c
@@ -828,7 +828,7 @@ int HandleEvent(event, donep)
 	debkludge_offy = eHIGH-xwa.height+p_offy;
       }
 
-#if 0
+#if 1
       /* FIXME: if we want to do this, we first have to wait for a configure
        * notify to avoid a race condition because the location might be in-
        * correct if the window manager does placement after managing the window.
