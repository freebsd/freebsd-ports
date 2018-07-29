--- src/Utils/FileUtils.cpp.orig	2018-07-05 04:33:27 UTC
+++ src/Utils/FileUtils.cpp
@@ -48,7 +48,7 @@
 static int desens_partial(DIR * dir, char * io_file)
 {
  struct dirent* de;
- while (de = readdir(dir))
+ while ((de = readdir(dir)) != NULL)
  {
   if (!strcasecmp(io_file, de->d_name))
   {
@@ -668,4 +668,4 @@ int FILE_compress_dir(const string& src_
 	
 	return r;
 	
-}
\ No newline at end of file
+}
