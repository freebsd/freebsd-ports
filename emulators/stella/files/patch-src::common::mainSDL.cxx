--- src/common/mainSDL.cxx.orig	Fri Aug  6 10:51:15 2004
+++ src/common/mainSDL.cxx	Thu Sep 30 21:00:45 2004
@@ -822,7 +822,11 @@
   const char* file = argv[argc - 1];
 
   // Open the cartridge image and read it in
+#if defined(__GNUC__) && __GNUC__ < 3
+  ifstream in(file, ios::binary);
+#else
   ifstream in(file, ios_base::binary);
+#endif
   if(!in)
   {
     cerr << "ERROR: Couldn't open " << file << "..." << endl;
