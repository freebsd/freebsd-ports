--- src/Basic/Types/basic.gen.h.orig	Sun Nov 24 20:55:47 2002
+++ src/Basic/Types/basic.gen.h	Sun Nov 24 20:56:09 2002
@@ -24,10 +24,6 @@
 typedef int SI;
 typedef void* pointer;
 
-void* operator new (register size_t s);
-void  operator delete (register void* ptr);
-void* operator new[] (register size_t s);
-void  operator delete[] (register void* ptr);
 int   mem_used ();
 void  mem_info ();
 bool  debug (int which, bool write_flag= FALSE);
