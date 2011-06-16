--- apps/x11_main.c.orig	2011-04-29 14:06:09.000000000 -0500
+++ apps/x11_main.c	2011-06-11 02:15:12.203411543 -0500
@@ -482,9 +482,7 @@ void winreloadfile(pdfapp_t *app)
 
 void winopenuri(pdfapp_t *app, char *buf)
 {
-	char *browser = getenv("BROWSER");
-	if (!browser)
-		browser = "open";
+	char browser[] = "xdg-open";
 	if (fork() == 0)
 		execlp(browser, browser, buf, (char*)0);
 }
@@ -563,6 +561,24 @@ static void winresettmo(struct timeval *
 	tmo_at->tv_usec = 0;
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
@@ -571,7 +587,7 @@ int main(int argc, char **argv)
 	KeySym keysym;
 	int oldx = 0;
 	int oldy = 0;
-	int resolution = 72;
+	int resolution = get_dpi();
 	int pageno = 1;
 	int wasshowingpage;
 	struct timeval tmo, tmo_at;
