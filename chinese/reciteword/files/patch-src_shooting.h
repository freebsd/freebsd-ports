--- src/shooting.h.orig	2002-12-28 19:42:09.000000000 +0800
+++ src/shooting.h	2007-07-30 16:38:45.000000000 +0800
@@ -16,15 +16,15 @@
 	int mousein;
 	int enable;
 	int active;
-	void (*runfunc1) (gint);
-	void (*runfunc2) (gint);
+	void (*runfunc1) (glong);
+	void (*runfunc2) (glong);
 	gint funcdata;
 
 	  tLabelItem ();
 	void init ();
 	void create (GtkWidget * pfixed, gint x, gint y, gint w, gint h,
 		     GdkPixmap * pix_1, GdkPixmap * pix_2, gchar * str,
-		     void (*func1) (gint), void (*func2) (gint), gint data);
+		     void (*func1) (glong), void (*func2) (glong), gint data);
 	void set_label (gchar * str);
 	void set_enable (gint a);
 	void draw ();
