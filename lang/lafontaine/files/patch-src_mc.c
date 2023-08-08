--- src/mc.c.orig	2002-05-18 22:11:05 UTC
+++ src/mc.c
@@ -34,8 +34,9 @@
 #include "debug.h"
 
 /*>>> here is the declaration of the turtle            */
-struct s_turtle my_turtle;
+extern struct s_turtle my_turtle;
 
+void mc_free(void);
 
 /**
    Freeing and reinitializing all middle-code informations.<br>
