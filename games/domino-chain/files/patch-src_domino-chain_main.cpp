--- src/domino-chain/main.cpp.orig	2020-02-09 08:53:36 UTC
+++ src/domino-chain/main.cpp
@@ -40,15 +40,8 @@
 
 static std::string getDataDir(void)
 {
-  const std::string portable_datadir = "./data";
-  struct stat st;
-  if (stat(portable_datadir.c_str(), &st) == 0) {
-      std::cout << "Using portable datadir: " << portable_datadir << std::endl;
-      return portable_datadir;
-  } else {
       std::cout << "Using system datadir: " << DATADIR << std::endl;
       return DATADIR;
-  }
 }
 
 static LevelState playTick(figure_c & a, graphics_c & gr, unsigned int keys)
