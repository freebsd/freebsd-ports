--- my_thread_process.hh.orig	Fri Dec 22 16:09:57 2006
+++ my_thread_process.hh	Fri Dec 22 16:10:18 2006
@@ -32,7 +32,7 @@
   sequence* my_sequence;
   unsigned char * data;
   unsigned char** data_images;
-  bool my_thread_process::conditions_for_break(int i,type_of_current_reading cr);
+  bool conditions_for_break(int i,type_of_current_reading cr);
 public:
   bool should_continue;
   my_thread_process(my_frame& frame,buffer& buf,sequence& seq);
