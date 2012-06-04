--- apps/x11_main.c.orig	2012-03-29 05:46:53.000000000 -0500
+++ apps/x11_main.c	2012-04-07 14:37:40.754315181 -0500
@@ -602,6 +602,24 @@ static void usage(void)
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
