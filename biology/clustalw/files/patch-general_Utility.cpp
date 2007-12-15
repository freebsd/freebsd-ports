--- general/Utility.cpp.orig	Wed May 23 22:47:41 2007
+++ general/Utility.cpp	Wed Oct 31 17:19:21 2007
@@ -144,7 +144,7 @@
     while (true)
     {
         fprintf(stdout, "%s (%.1f-%.1f)   [%.1f]: ", instr, minx, maxx, def);
-        gets(line);
+        fgets(line, 1024, stdin);
         status = sscanf(line, "%f", &ret);
         if (status == EOF)
         {
@@ -181,7 +181,7 @@
     while (true)
     {
         fprintf(stdout, "%s (%d..%d)    [%d]: ", instr, minx, maxx, def);
-        gets(line);
+        fgets(line, 1024, stdin);
         status = sscanf(line, "%d", &ret);
         if (status == EOF)
         {
