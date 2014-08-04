--- ./platform/x11/x11_main.c.orig	2014-06-10 17:09:28.000000000 +0200
+++ ./platform/x11/x11_main.c	2014-08-04 18:51:44.000000000 +0200
@@ -794,6 +794,24 @@
 	exit(1);
 }
 
+/* reference:
+ * http://stackoverflow.com/questions/2621439/how-to-get-screen-dpi-linux-mac-programatically
+ */
+int get_dpi(void)
+{
+	Display *xdpy;
+	int xscr;
+	int x = 0;
+
+	if ((xdpy = XOpenDisplay(NULL))) {
+		xscr = DefaultScreen(xdpy);
+		x = (int) (DisplayWidth(xdpy, xscr) * 25.4 /
+				DisplayWidthMM(xdpy, xscr) + 0.5);
+		XCloseDisplay(xdpy);
+	}
+	return x;
+}
+
 int main(int argc, char **argv)
 {
 	int c;
