
$FreeBSD$

--- source/unix/fileio.h	2001/02/17 17:39:14	1.1
+++ source/unix/fileio.h	2001/02/17 17:39:23
@@ -65,7 +65,7 @@
  const char* pathdelimitterstring = "/";
 
  #define CASE_SENSITIVE_FILE_NAMES 1
- #define USE_HOME_DIRECTORY 1
+ #define USE_HOME_DIRECTORY 0
 
  const int maxfilenamelength = 255;
  const char* asc_configurationfile = "~/.asc/ascrc";
