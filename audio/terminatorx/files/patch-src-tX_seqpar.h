--- src/tX_seqpar.h.orig	Fri Aug 27 13:16:57 2004
+++ src/tX_seqpar.h	Fri Aug 27 13:18:07 2004
@@ -94,9 +94,9 @@
 	static tX_seqpar *get_sp_by_persistence_id(unsigned int pid);
 
 	void record_value (const float value);
-	virtual void do_exec(const float value)=NULL;
-	virtual void exec_value(const float value)=NULL;	
-	virtual void do_update_graphics()=NULL;
+	virtual void do_exec(const float value)=0;
+	virtual void exec_value(const float value)=0;	
+	virtual void do_update_graphics()=0;
 	void update_graphics();
 	static void update_all_graphics();
 	static void init_all_graphics();
