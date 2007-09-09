--- CUnit/Sources/Framework/MyMem.c.orig	Wed Jul 25 16:47:05 2007
+++ CUnit/Sources/Framework/MyMem.c	Wed Jul 25 16:47:40 2007
@@ -340,8 +340,8 @@
   setvbuf(pFile, NULL, _IONBF, 0);
 
   fprintf(pFile, "<\?xml version=\"1.0\" \?>");
-  fprintf(pFile, "\n<\?xml-stylesheet type=\"text/xsl\" href=\"Memory-Dump.xsl\" \?>");
-  fprintf(pFile, "\n<!DOCTYPE MEMORY_DUMP_REPORT SYSTEM \"Memory-Dump.dtd\">");
+  fprintf(pFile, "\n<\?xml-stylesheet type=\"text/xsl\" href=\"/usr/local/share/CUnit/Memory-Dump.xsl\" \?>");
+  fprintf(pFile, "\n<!DOCTYPE MEMORY_DUMP_REPORT SYSTEM \"/usr/local/share/CUnit/Memory-Dump.dtd\">");
   fprintf(pFile, "\n<MEMORY_DUMP_REPORT>");
   fprintf(pFile, "\n  <MD_HEADER/>");
   fprintf(pFile, "\n  <MD_RUN_LISTING>");
