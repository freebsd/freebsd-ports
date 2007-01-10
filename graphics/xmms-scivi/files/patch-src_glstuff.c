--- src/glstuff.c.orig	Wed Jan 10 19:23:52 2007
+++ src/glstuff.c	Wed Jan 10 19:26:44 2007
@@ -120,15 +120,15 @@
 
 #define GET(_fatal_, _n_)\
 	if (!dontload){\
-		((void*)(sc_##_n_)) = getaddr(#_n_); \
+		sc_##_n_ = (void *)getaddr(#_n_); \
 		if ((sc_##_n_) == NULL) { \
-			((void*)(sc_##_n_)) = stub_func; \
+			sc_##_n_ = (void *)stub_func; \
 			eprintf("failed to get address of '%s'\n", #_n_);\
 			if ((_fatal_)) failed++;\
 		}\
 		/* eprintf("func %s @ %p\n", #_n_, sc_##_n_);*/ \
 	} else \
-		((void*)(sc_##_n_)) = stub_func;
+		sc_##_n_ = (void *)stub_func;
 
 	getaddr = sc_glXGetProcAddress ?
 		((void*)sc_glXGetProcAddress) :
