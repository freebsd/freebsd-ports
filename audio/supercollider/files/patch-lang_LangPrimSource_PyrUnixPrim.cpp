--- lang/LangPrimSource/PyrUnixPrim.cpp.orig	2017-03-20 15:18:39 UTC
+++ lang/LangPrimSource/PyrUnixPrim.cpp
@@ -179,7 +179,7 @@ int prString_POpen(struct VMGlobals *g, int numArgsPus
 		return errFailed;
 	}
 
-	thread thread(std::bind(string_popen_thread_func, process));
+	std::thread thread(std::bind(string_popen_thread_func, process));
 	thread.detach();
 
 	SetInt(a, pid);
@@ -249,7 +249,7 @@ int prArrayPOpen(struct VMGlobals *g, int numArgsPushe
 		return errFailed;
 	}
 
-	thread thread(std::bind(string_popen_thread_func, process));
+	std::thread thread(std::bind(string_popen_thread_func, process));
 	thread.detach();
 
 	for (int i=1; i<obj->size; ++i) {
