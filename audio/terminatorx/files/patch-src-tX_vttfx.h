--- src/tX_vttfx.h.orig	Fri Aug 27 13:14:20 2004
+++ src/tX_vttfx.h	Fri Aug 27 13:20:34 2004
@@ -56,15 +56,15 @@
 	void set_vtt(void *v) { vtt=v;}
 	void *get_vtt() { return vtt; }
 	
-	virtual void activate()=NULL;
-	virtual void deactivate()=NULL;
-	virtual void run()=NULL;	
-	virtual int isEnabled()=NULL;
+	virtual void activate()=0;
+	virtual void deactivate()=0;
+	virtual void run()=0;	
+	virtual int isEnabled()=0;
 	virtual void reconnect_buffer();
 	
 	virtual const char *get_info_string()=NULL;
 	
-	virtual void save(FILE *rc, gzFile rz, char *indent)=NULL;
+	virtual void save(FILE *rc, gzFile rz, char *indent)=0;
 	
 	GtkWidget* get_panel_widget() { return panel_widget; }
 	void set_panel_widget(GtkWidget *widget) { panel_widget=widget; }
