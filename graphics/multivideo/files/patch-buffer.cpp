--- buffer.cpp.orig	Thu Jan 31 18:46:26 2002
+++ buffer.cpp	Sun Oct  5 03:33:25 2003
@@ -20,6 +20,9 @@
 #include <iostream>
 #include "buffer.hh"
 
+wxMutex load_thread_cond_mutex;
+wxMutex thread_proc_cond_mutex;
+
 buffer::buffer(int nb_pictures, int size,bool free) :
   number_of_pictures(nb_pictures),
   buffer_size(size),
@@ -35,8 +38,8 @@
   mutex_first_image             (new wxMutex()),
   mutex_loaded_image            (new wxMutex()),
   mutex_last_position           (new wxMutex()),
-  load_thread_you_can_load      (new wxCondition()),
-  thread_process_you_can_process(new wxCondition())
+  load_thread_you_can_load      (new wxCondition(load_thread_cond_mutex)),
+  thread_process_you_can_process(new wxCondition(thread_proc_cond_mutex))
 {
   images.resize(number_of_pictures+1);
   images_process.resize(number_of_pictures+1);
@@ -429,7 +432,7 @@
   {
     delete load_thread_you_can_load;
   }
-  load_thread_you_can_load=new wxCondition();
+  load_thread_you_can_load=new wxCondition(load_thread_cond_mutex);
 }
 
 void buffer::initialize_condition_process()
@@ -438,5 +441,5 @@
   {
     delete thread_process_you_can_process;
   }
-  thread_process_you_can_process=new wxCondition();
+  thread_process_you_can_process=new wxCondition(thread_proc_cond_mutex);
 }
