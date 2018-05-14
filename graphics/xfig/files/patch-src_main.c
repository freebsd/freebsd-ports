--- src/main.c.orig	2018-04-04 21:07:37 UTC
+++ src/main.c
@@ -631,7 +631,7 @@ struct  geom   geom;
 int setup_visual (int *argc_p, char **argv, Arg *args);
 void get_pointer_mapping (void);
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
     Widget	    children[NCHILDREN];
     XEvent	    event;
