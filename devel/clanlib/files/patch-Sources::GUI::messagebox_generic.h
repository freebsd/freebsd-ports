--- Sources/GUI/messagebox_generic.h.orig	Wed May 30 21:37:42 2007
+++ Sources/GUI/messagebox_generic.h	Wed May 30 21:38:24 2007
@@ -26,7 +26,7 @@
 		const std::string &button2,
 		const std::string &button3);
 
-	CL_MessageBox_Generic::~CL_MessageBox_Generic();
+	~CL_MessageBox_Generic();
 
 	void set_text(const std::string &text);
 
