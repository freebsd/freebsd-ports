Ensure jfsw and build files get created within $HOME/.jfsw

--- jfbuild/src/sdlayer.c.orig	2014-11-19 11:24:19.905905262 +0100
+++ jfbuild/src/sdlayer.c	2014-11-19 11:36:43.045765953 +0100
@@ -152,6 +152,16 @@
 {
 	int r;
 	
+#ifdef __FreeBSD__
+    /* XXX Ensure every jfsw file gets created within $HOME/.jfsw */
+    if (chdir(getenv("HOME")) != 0)
+        err(1, "cannot cd to $HOME");
+    if (mkdir(".jfsw", 0755) != 0 && errno != EEXIST)
+        err(1, "cannot mkdir $HOME/.jfsw");
+    if (chdir(".jfsw") != 0)
+        err(1, "cannot cd to $HOME/.jfsw");
+#endif
+	
 	buildkeytranslationtable();
 	
 #ifdef HAVE_GTK2
