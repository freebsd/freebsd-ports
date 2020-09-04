Ensure jfsw and build files get created within $HOME/.jfsw

--- jfbuild/src/sdlayer.c.orig	2020-09-03 06:19:21 UTC
+++ jfbuild/src/sdlayer.c
@@ -152,6 +152,16 @@ int main(int argc, char *argv[])
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
