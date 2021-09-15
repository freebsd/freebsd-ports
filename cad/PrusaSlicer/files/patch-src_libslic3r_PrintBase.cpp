--- src/libslic3r/PrintBase.cpp.orig	2021-07-16 10:14:03 UTC
+++ src/libslic3r/PrintBase.cpp
@@ -97,7 +97,7 @@ void PrintBase::status_update_warnings(ObjectID object
     	printf("%s warning: %s\n", (object_id == this->id()) ? "print" : "print object", message.c_str());
 }
 
-tbb::mutex& PrintObjectBase::state_mutex(PrintBase *print)
+std::mutex& PrintObjectBase::state_mutex(PrintBase *print)
 { 
 	return print->state_mutex();
 }
