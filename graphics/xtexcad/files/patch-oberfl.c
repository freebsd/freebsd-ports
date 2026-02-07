--- oberfl.c.orig
+++ oberfl.c
@@ -161,7 +161,7 @@
 static void SetTitle(void);
 static void SetNewZoom(void);
 
-void main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
 	Widget topForm;
 	Pixel background;
