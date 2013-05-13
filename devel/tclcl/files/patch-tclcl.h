--- tclcl.h.orig	2013-05-13 09:20:07.000000000 +0200
+++ tclcl.h	2013-05-13 09:23:19.000000000 +0200
@@ -85,7 +85,7 @@
 	/* may not work at all! */
 	inline char* result() const { return (tcl_->result); }
 #endif  /* TCL_MAJOR_VERSION >= 8 */
-	inline void result(const char* p) { tcl_->result = (char*)p; }
+	inline void result(const char* p) {Tcl_SetResult (tcl_, (char *)p, NULL);}
 	void resultf(const char* fmt, ...);
 	inline void CreateCommand(const char* cmd, Tcl_CmdProc* cproc,
 				  ClientData cd = 0,
