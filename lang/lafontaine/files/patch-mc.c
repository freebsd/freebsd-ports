--- src/mc.c.orig	Sun Aug 15 20:00:39 2004
+++ src/mc.c	Sun Aug 15 20:01:11 2004
@@ -36,6 +36,7 @@
 /*>>> here is the declaration of the turtle            */
 struct s_turtle my_turtle;
 
+void mc_free(void);
 
 /**
    Freeing and reinitializing all middle-code informations.<br>
