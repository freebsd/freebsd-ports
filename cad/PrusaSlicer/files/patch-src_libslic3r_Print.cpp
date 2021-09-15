--- src/libslic3r/Print.cpp.orig	2021-07-16 10:14:03 UTC
+++ src/libslic3r/Print.cpp
@@ -36,7 +36,7 @@ template class PrintState<PrintObjectStep, posCount>;
 
 void Print::clear() 
 {
-	tbb::mutex::scoped_lock lock(this->state_mutex());
+	std::scoped_lock<std::mutex> lock(this->state_mutex());
     // The following call should stop background processing if it is running.
     this->invalidate_all_steps();
 	for (PrintObject *object : m_objects)
@@ -262,7 +262,7 @@ bool Print::is_step_done(PrintObjectStep step) const
 {
     if (m_objects.empty())
         return false;
-    tbb::mutex::scoped_lock lock(this->state_mutex());
+    std::scoped_lock<std::mutex> lock(this->state_mutex());
     for (const PrintObject *object : m_objects)
         if (! object->is_step_done_unguarded(step))
             return false;
@@ -617,7 +617,7 @@ Print::ApplyStatus Print::apply(const Model &model, Dy
         update_apply_status(false);
 
     // Grab the lock for the Print / PrintObject milestones.
-	tbb::mutex::scoped_lock lock(this->state_mutex());
+	std::scoped_lock<std::mutex> lock(this->state_mutex());
 
     // The following call may stop the background processing.
     if (! print_diff.empty())
