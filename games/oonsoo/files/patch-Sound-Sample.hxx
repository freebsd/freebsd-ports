--- Sound/Sample.hxx.orig	Fri Dec 22 17:29:22 2006
+++ Sound/Sample.hxx	Fri Dec 22 17:29:58 2006
@@ -26,7 +26,7 @@
  
   public:
     // Constructor
-    Sample::Sample(unsigned char* sampleData);
+    Sample(unsigned char* sampleData);
 
     // Destructor 
     virtual ~Sample();
